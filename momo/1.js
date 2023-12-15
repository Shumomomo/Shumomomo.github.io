    function uploadFile() {
        var fileInput = document.getElementById("fileToUpload");
        var file = fileInput.files[0];

        var reader = new FileReader();
        reader.readAsBinaryString(file);
        reader.onload = function() {
            var fileContent = reader.result;

            var xhr = new XMLHttpRequest();
            xhr.open("POST", "upload.php"); // 指定服务器脚本文件
            xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
            xhr.onreadystatechange = function() {
                if (xhr.readyState === 4 && xhr.status === 200) {
                    // 在这里处理服务器的响应
                }
            };
            xhr.send(fileContent);
        };
    }