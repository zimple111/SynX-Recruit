
# <center><font face="楷体" size=6>遇到的问题和解决方案</font></center>
## 一.github网站的使用
- github在国内无其他手段的情况下访问速度过慢甚至打不开，在网络上搜索教程后选取了合法合规的方法来改善，如使用浏览器插件（我用的是Edge上的 github Enhance）
- <a href="https://imgse.com/i/pV7p6Xt"><img src="https://s21.ax1x.com/2025/10/04/pV7p6Xt.png" alt="pV7p6Xt.png" border="0" width="50%" /></a>

    加速器（我使用的是steam++）
- <a href="https://imgse.com/i/pV7py6I"><img src="https://s21.ax1x.com/2025/10/04/pV7py6I.png" alt="pV7py6I.png" border="0" width="70%"/></a>
- 还有一些镜像网站，总之不论哪种方法都可以有效解决这个问题
## 二.markdown的使用
- markdown是一种轻量级标记语言，通过简单符号编写结构化文本，并可转换为HTML,PDF等格式。但此前从未接触过，通过网络上搜索教程学习，掌握了一些基本语法。中间遇到图片的问题，找到了使用图床并结合HTML实现图片的导入，在图床网站上传本地图片后会生成一个HTML的地址，直接复制过来简单调整参数就可使用，本文档内的图片均由此得来。
- <a href="https://imgse.com/i/pV7po1s"><img src="https://s21.ax1x.com/2025/10/04/pV7po1s.png" alt="pV7po1s.png" border="0" /></a>
## 三.使用git将本地代码推送到github远程仓库上
- 通过网络资料学习发现，基本有两种方法连接（以github为例） 
    - 第一种是HTTPS地址+远程仓库账号密码（github  2021年宣布停用但实际操作中仍然可以使用）目前正在使用
    - 第二种是用户名+PAT令牌
    - 第三种是SSH链接+密钥
- 以上方法均已尝试，目前学习阶段选择了第一种方法，虽安全性差但较为便捷。
## 四.在上传代码时报错
<a href="https://imgse.com/i/pV7pvh4"><img src="https://s21.ax1x.com/2025/10/04/pV7pvh4.jpg" alt="pV7pvh4.jpg" border="0" /></a>
经分析后得到此原因是远程分支和本地分支不同步，远程仓库拒绝了本地仓库上传的文件。应在git push之前git pull来获取并整合远程仓库的最新更改或者git push --force强制推送
