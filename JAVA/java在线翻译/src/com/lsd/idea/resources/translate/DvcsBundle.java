package com.lsd.idea.resources.translate;

import com.baidu.translate.demo.TransApi;
import com.com.lsd.idea.bean.ResourcesBean;
import net.sf.json.JSONArray;
import net.sf.json.JSONObject;
import org.junit.Test;

import java.net.URLEncoder;
import java.sql.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class DvcsBundle {

    private static final String USER = "root";
    private static final String PASS = "12345678";
    //private static final String PASS = "zzzxxxccc";
    private static final String DB_URL = "jdbc:mysql://localhost:3306/IdeaTranslate?useUnicode=true&characterEncoding=UTF-8&useSSL=false";
    //private static final String DB_URL = "jdbc:mysql://localhost:3306/IdeaResources?useUnicode=true&characterEncoding=UTF-8&useSSL=false";
    
    private String tablename = "UltimateFeaturesBundle";


    private static Connection conn = null;
    private static PreparedStatement ps = null;
    private static ResultSet rs = null;


    /**
     * 获取数据库连接
     */
    public void getConn() {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            // 打开一个连接
            conn = DriverManager.getConnection(DB_URL, USER, PASS);

            if (conn != null) {
                System.out.println("数据库连接成功！");
            }

        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        }
    }

    /**
     * 关闭数据库连接
     */
    public void destoryConn() {
        try {
            if (rs != null) {
                rs.close();
            }

            if (ps != null) {
                ps.close();
            }

            if (conn != null) {
                conn.close();
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }

    }


    public List<ResourcesBean> getList() {
        getConn();
        //String sql = "select * from com_intellij_dvcs_ui_DvcsBundle";
        String sql = "select * from "+tablename;
        List<ResourcesBean> list = new ArrayList<>();
        try {
            ps = conn.prepareStatement(sql);
            rs = ps.executeQuery();
            while (rs.next()) {
                ResourcesBean resourcesBean = new ResourcesBean();
                resourcesBean.setId(rs.getInt("id"));
                resourcesBean.setKeyname(rs.getString("keyname"));
                resourcesBean.setValue(rs.getString("value"));
                list.add(resourcesBean);
            }

        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            destoryConn();
        }
        return list;
    }
    
    @Test
    public void getAllList() {
        getConn();
        //String sql = "select * from com_intellij_dvcs_ui_DvcsBundle";
        String sql = "select * from "+tablename;
        try {
            ps = conn.prepareStatement(sql);
            rs = ps.executeQuery();
            while (rs.next()) {
                System.out.println(rs.getString("keyname")+"="+rs.getString("unicode"));
            }
            
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            destoryConn();
        }
    }

    @Test
    public void translate() {
        List<ResourcesBean> list = getList();
        for (ResourcesBean rb : list) {
            //初始化百度翻译API
            TransApi api = new TransApi();
            String result = api.getTransResult(rb.getValue(), "en", "zh");
            System.out.println(result);
            JSONObject object = JSONObject.fromObject(result);
            JSONArray array = object.getJSONArray("trans_result");
            JSONObject obj2 = JSONObject.fromObject(array.get(0));
            saveToDB(rb.getId(),obj2.get("dst").toString(),converToUnicode(obj2.get("dst").toString()));

        }
        System.out.println("完成！");
    }

    /**
     * 将传入的中文字符转成Unicode编码
     *
     * @param str
     * @return
     */
    private String converToUnicode(String str) {
        String result = "";
        for (int i = 0; i < str.length(); i++) {
            int chr1 = (char) str.charAt(i);
            if (chr1 >= 19968 && chr1 <= 171941) {//汉字范围 \u4e00-\u9fa5 (中文)
                result += "\\u" + Integer.toHexString(chr1);
            } else {
                result += str.charAt(i);
            }
        }
        return result;
    }


    /**
     * 将数据存入数据库
     *
     * @param id
     * @param res
     * @param unicode
     */
    private void saveToDB(int id, String res, String unicode) {
        getConn();
        String sql = "update `"+tablename+"` set translate=?,unicode=? where id=?";
        System.out.println(res + "=====>" + unicode);
        try {
            ps = conn.prepareStatement(sql);
            ps.setString(1, res);
            ps.setString(2, unicode);
            ps.setInt(3, id);
            ps.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            destoryConn();
        }
    }
}
