
//#include"funtion.h"//funtion头文件
#include"funtion.h"


int now = 1;//循环时使用
int i;//函数中的通用变量
int main()//主函数
{
	int flag;
	flag = check();
	if (flag == 1)//判断是否已创建管理员账号
	{
		creataccount();
	}
	menu();//菜单
	return 0;
}