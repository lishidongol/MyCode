/**
     * SpringMVC 下载文件例子
     * 解决下载文件内容乱码，需要在springmvc配置文件<mvc:annotation-driven>中添加（注意优先级）：
     * <bean class="org.springframework.http.converter.ByteArrayHttpMessageConverter"/>
     * @param request
     * @param filename
     * @return
     * @throws IOException
     */
    @RequestMapping("/getImportQuestionsTemplate")
    public ResponseEntity<byte[]> getImportQuestionsTemplate(HttpServletRequest request,String filename) throws IOException {
        String path = request.getServletContext().getRealPath("/excel/");
        File file = new File(path + File.separator + filename);
        System.out.println(path);
        HttpHeaders headers = new HttpHeaders();
        //下载显示的文件名，解决中文名称乱码问题
        String downloadFielName = new String(filename.getBytes("UTF-8"),"iso-8859-1");
        //通知浏览器以attachment（下载方式）打开文件
        headers.setContentDispositionFormData("attachment", downloadFielName);
        //application/octet-stream ： 二进制流数据（最常见的文件下载）。
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        return new ResponseEntity<byte[]>(FileUtils.readFileToByteArray(file),
                headers, HttpStatus.CREATED);
    }