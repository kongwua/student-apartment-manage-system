学生公寓管理系统使用说明

背景:我是一名计算机专业的大一新生,这是我花了两周左右写出来的一个c语言课程设计,有点过于简陋,其中还有很多地方需要优化.但是这是我写的第一个项目,具有极大的纪念价值.

1.	注册管理员账号
   
第一次进入系统时，会要求注册管理员账号，账号和密码都不能超过20个字符。
请记住注册的账号和密码，系统无密码找回功能
 
3.	菜单界面
 
输入相应选项对应的数字进入相应的模块，当输入不在范围内的数字时，会刷新并重新要求输入

4.	登录模块

输入学生账号和密码进入学生端，学生端可以查看有空余床位的宿舍床位情况
 
 
5.注册模块

注册学生账号，账号和密码输入不能超过20个字符。输入第一次密码后会要求再次输入密码，当多次输入不正确时会退出注册模块

6.	修改学生端密码模块、

输入学生账号和密码，正确后会要求输入新密码。新密码长度不能超过20个字符

8.	管理员登录模块

输入管理员账号密码，登录管理员端，之后会有管理员菜单
 
9.	录入住宿信息模块

进入时先输入要输入数据的次数，之后进入循环。
按要求和顺序输入数据信息。注意不能输入中文，只能输入字母。每种数据必须用空格间隔开。床位数量不能小于已分配床位数量，否则会要求重新输入

8.	查询住宿信息模块
 
选择后进入查询菜单，输入数字进入相应的功能模块。

查询有空余床位的宿舍

将所有有空余床位的宿舍打印出来

查询学院床位情况

进入后先选择要查询的学院，在选择要查询的类别：全学院、女生、男生

查询公寓床位情况

进入后有 全部公寓查询（将所有公寓情况打印出来）、自定义范围查询（自定义生活区和栋数范围进行查询，其中开始栋数不能大于结束栋数）、单间宿舍查询三种选择。

统计空床情况

进入后有公寓类别查询和学院类别查询。公寓类别查询：输入生活区、开始栋数和结束栋数，会统计总空床数和每一栋宿舍的空床数。学院类别查询：输入学院名（只能是英文），会统计学院总空床数和男女生的空床数。

9.	更改住宿信息模块

分为更改住宿信息和删除住宿信息两个功能。两个功能都是先要求输入循环的次数，然后要求输入生活区、栋数和房间号，查找相应的宿舍。若找到，则询问是否进行操作，只能输入Y/N或y/n。

10.	修改管理员账号模块

可以选择修改账号或修改密码，但新账号和密码都不能超过20个字符。无删除账号功能。

11.	备份模块

含存入备份和读取备份两个功能。

12.	管理学生账号信息功能

含查看所有学生账号和密码、修改学生账号密码两个功能。新输入的账号和密码都不能超过20个字符。
