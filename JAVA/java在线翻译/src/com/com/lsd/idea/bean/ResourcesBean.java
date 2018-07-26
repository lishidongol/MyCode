package com.com.lsd.idea.bean;

public class ResourcesBean {
    private int id;
    private String keyname;
    private String value;
    private String translate;
    private String unicode;

    public String getUnicode() {
        return unicode;
    }

    public void setUnicode(String unicode) {
        this.unicode = unicode;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getKeyname() {
        return keyname;
    }

    public void setKeyname(String keyname) {
        this.keyname = keyname;
    }

    public String getValue() {
        return value;
    }

    public void setValue(String value) {
        this.value = value;
    }

    public String getTranslate() {
        return translate;
    }

    public void setTranslate(String translate) {
        this.translate = translate;
    }

    @Override
    public String toString() {
        return "ResourcesBean{" +
                "id=" + id +
                ", keyname='" + keyname + '\'' +
                ", value='" + value + '\'' +
                ", translate='" + translate + '\'' +
                ", unicode='" + unicode + '\'' +
                '}';
    }
}
