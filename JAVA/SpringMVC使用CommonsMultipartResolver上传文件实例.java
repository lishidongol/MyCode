		@ResponseBody
    @RequestMapping("uploadQuestionExcel")
    public Map uploadQuestionExcel(HttpServletRequest request, HttpServletResponse response) {
        //实例化一个文件解析器
        CommonsMultipartResolver commonsMultipartResolver = new CommonsMultipartResolver(request.getSession().getServletContext());
        //判断request请求是否有文件上传
        if (commonsMultipartResolver.isMultipart(request)) {
            //转换request
            MultipartHttpServletRequest multiRequest = (MultipartHttpServletRequest) request;
            //获得文件,和单文件不同在于方法是getFiles得到List集合
            MultipartFile file = multiRequest.getFile("file");
            if (!file.isEmpty()) {
                //获得原始文件名
                String fileName = file.getOriginalFilename();
                String newFileName = UUID.randomUUID() + fileName;
                //获得物理路径，webapp所在路径
                String file_path = request.getSession().getServletContext().getRealPath("/excel/uploadTemp");
                //判断存储文件的物理路径文件夹是否存在，如果文件夹不存在就创建
                File fileForPath = new File(file_path);
                if (!fileForPath.exists()) {
                    System.out.println("file not exists");
                    boolean iscreate = fileForPath.mkdir();
                }
                //System.out.println("文件路径，可用于回显：" + file_path + "\\" + newFileName);
                //新文件路径实例
                File targetFile = new File(file_path, newFileName);
                //上传文件保存路径加文件名
                System.out.println(targetFile.getPath());
                try {
                    //开始保存文件
                    file.transferTo(targetFile);
                } catch (IllegalStateException | IOException e) {
                    e.printStackTrace();
                }
            }

        }else {
            return Msg.msg(1,"无效的文件");
        }
        return Msg.ok();
    }