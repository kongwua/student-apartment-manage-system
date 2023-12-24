#include "funtion.h"



int check()//检查有无注册管理员账号
{

	FILE* fp=NULL;//文件指针
	fp = fopen("Adm.dat", "rb+");
	char first;
	first = fgetc(fp);
	if (first == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



void creataccount()//创建管理员账号
{
	Adm guanli;
	FILE* fp;//文件指针
	fp = fopen("Adm.dat", "rb+");
	char a[20], b[20];
	printf("\t\t请输入管理员账号： ");
	scanf("%s", a);
	printf("\t\t请输入管理员密码： ");
	scanf("%s", b);
	strcpy(guanli.adm_ZH, a);
	strcpy(guanli.adm_Pass, b);//复制账号密码到文件中
	fwrite(&guanli, sizeof(Adm), 1, fp);
	fclose(fp);
	printf("\n\t\t注册账号成功！  ");
	Sleep(1000);//延时1s关闭
	return;
}



void menu()//菜单模块
{
	int option = 0;
	printf("\n\t\t\t------------------------------\n\t\t\t欢迎使用学生公寓管理系统\n\t\t\t------------------------------\n");
	system("color 1F");//程序面板颜色调节
	while (now)
	{
		system("cls");//每次循环开始时刷新屏幕
		do
		{
			system("cls");
			printf("\n                 -----------------------菜单--------------------\n");
			printf("\t\t|\t          ①登录                        |\n");
			printf("\t\t|\t          ②注册                        |\n");
			printf("\t\t|\t          ③修改密码                    |\n");
			printf("\t\t|\t          ④管理员登录                  |\n");
			printf("\t\t|\t          ⑤退出系统                    |\n");
			printf("\n                 -----------------------------------------------\n");
			printf("\n");
			printf("\t\t请输入选项:  [\t ]\b\b\b\b");
			scanf("%d", &option);//对option进行赋值
		} while (option > 5|| option < 1);//管理模块选项为1111
		tran(option);//中转
	}
		
}




void tran(int math)//中转
{
	switch(math)
	{
		case 1:
			login();//登录
			break;
		case 2:
			regist();//注册
			break;
		case 3:
			changepass();//改密
			break;
		case 4:
			administor();//管理员登录
			break;
		case 5:
			printf("已退出系统\n欢迎下次使用!!!");
			now = 0;
			exit(0);
	}
}




void regist()//注册模块
{
	system("cls");//清屏
	char c[20];
	Ac a, b;//创建用户单元变量
	FILE* fp;
	printf("\n\t\t注册界面\n");
	Sleep(500);//延时0.5s
	fp = fopen("Users.dat", "rb+");
	fread(&b, sizeof(Ac), 1, fp);
	printf("\n\t\t请设置账号:[ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b");
	scanf("%s", &a.ZH);
	while (1)//检查是否已存在账号
	{
		if (strcmp(a.ZH, b.ZH))//文件中无相同账号
		{
			if (!feof(fp))//文件未结束时
			{
				fread(&b, sizeof(Ac), 1, fp);
			}
			else
			{
				break;
			}
		}
		else
		{
			printf("该账号已存在 ! ! !");
			Sleep(1000);
			fclose(fp);
			return;
		}
	}
	int time = 3;//记录输入密码的次数，time为0时退出程序
	do
	{
		system("cls");
		printf("\t\t请输入密码: [ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b");
		for (i = 0; i < 20; i++)//获取密码
		{
			a.Pass[i] = _getch();//不显示密码
			if (a.Pass[i] == '\r')//若输入回车,停止输入
			{
				break;
			}
			else if (a.Pass[i] == '\b' && i > 0)
			{
				i -= 2;
				printf("\b \b");//按下删除时
			}
			else
			{
				printf("*");//隐性密码
			}
		}
		a.Pass[i] = '\0';
		printf("\n");
		printf("\t\t请确认密码: [ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b");
		for (i = 0; i < 20; i++)
		{
			c[i] = _getch();//输入用以确认的密码
			if (c[i] == '\r')
			{
				break;
			}
			else if (c[i] == '\b' && i > 0)
			{
				i -= 2;
				printf("\b \b");//按下删除时
			}
			else
			{
				printf("*");
			}
		}
		c[i] = '\0';
		printf("\n");
		fclose(fp);
		if (!strcmp(a.Pass, c))//如果密码正确
		{
			FILE *fw = fopen("Users.dat", "ab+");//创建文件指针用来存储数据
			fwrite(&a, sizeof(Ac), 1, fw);//将数据写入文件
			fclose(fw);
			printf("\n%s,注册成功! ! !",a.ZH);
			Sleep(1000);
			return;
		}
		else//如果两次密码不同
		{
			if (time != 0)
			{
				printf("\n\n\t\t密码错误!\n\n\t\t请重新输入密码 ! !\n\n\t\t您还有%d次机会! ! !\n", time);
				time--;
				system("pause");
				continue;
			}
			else
			{
				printf("\n\t\t多次输入错误,即将退出! \n");
				fclose(fp);
				Sleep(1500);
				return;
			}

		}

	} while (time >= 0);
}




void login()//登录模块
{
	system("cls");//清屏
	Ac a, b;//定义两个用户结构体变量
	printf("\n登录界面\n");
	printf("账号 ： ");
	scanf("%s", &b.ZH);
	printf("\n密码： ");
	i = 0;
	for (i = 0; i < 20; i++)//读入密码
	{
		b.Pass[i] = _getch();//不显示密码
		if (b.Pass[i] == '\r')
		{
			break;
		}
	    else if (b.Pass[i] == '\b' && i > 0)
		{
			i-=2;
			printf("\b \b");//按下删除时
		}
		else
		{
			printf("*");
		}
	}
	b.Pass[i] = '\0';
	printf("\n");
	FILE* fp = fopen("Users.dat", "rb+");//创建文件指针用以获得用户信息
	fread(&a, sizeof(Ac), 1, fp);
	while (1)
	{
		if (strcmp(b.ZH, a.ZH) == 0)//检查文件中是否已经有该账号
		{
			break;
		}
		else
		{
			if (!feof(fp))//若文件未结束
			{
				fread(&a, sizeof(Ac), 1, fp);//继续读取
			}
			else
			{
				printf("账号错误或账号不存在！！！");
				Sleep(1000);
				fclose(fp);
				return;
			}
		}
	}
	fclose(fp);
 	if (strcmp(b.Pass, a.Pass) == 0)//若密码正确
	{
		printf("%s,欢迎登录！！！", a.ZH);
		Sleep(1000);
		system("cls");
		studentlook();
		return;
	}
	else
	{
		printf("密码错误！！！\n");
		Sleep(1000);
		system("cls");
		return;
	}
}


//学生端查看空余床位信息
void studentlook()
{
	printf("\t\t----------学生端---------\n");
	SearchFreebed();
}


void changepass()//更改密码模块
{
	system("cls");
	Ac a, b;
	printf("改密界面!!!\n");
	printf("请输入账号：");
	scanf("%s", &b.ZH);
	printf("\n请输入密码：");
	for (i = 0; i < 20; i++)
	{
		b.Pass[i] = _getch();//读入密码
		if (b.Pass[i] == '\r')
		{
			break;
		}
		else if (b.Pass[i] == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");//按下删除时
		}
		else
		{
			printf("*");
		}
	}
	b.Pass[i] = 0;
	printf("\n");
	FILE* fp = fopen("Users.dat", "rb+");//获取用户信息
	if (fp == NULL) return;
	fread(&a, sizeof(Ac), 1, fp);
	while (1)
	{
		if (strcmp(b.ZH, a.ZH) == 0)//检查文件中是否已经有该账号
		{
			break;
		}
		else
		{
			if (!feof(fp))//若文件未结束
			{
				fread(&a, sizeof(Ac), 1, fp);//继续读取
			}
			else
			{
				printf("账号错误或账号不存在！！！");
				Sleep(1000);
				fclose(fp);
				return;
			}
		}
	}
	if (strcmp(b.Pass, a.Pass) == 0)
	{
		printf("%s,密码正确！！！\n",a.ZH);
		char c[20], d[20];
		int time = 3;//记录输入确认密码次数
		do
		{
			printf("\t\t请设置新密码：[ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b");
			for (i = 0; i < 20; i++)
			{
				c[i] = _getch();//读入密码
				if (c[i] == '\r')
				{
					break;
				}
				else if (c[i] == '\b' && i > 0)
				{
					i -= 2;
					printf("\b \b");//按下删除时
				}
				else
				{
					printf("*");
				}
			}
			c[i] = '\0';
			printf("\n");
			printf("\t\t请确认密码：[ \t\t ]\b\b\b\b\b\b\b\b\b\b\b\b\b");
			for (i = 0; i < 20; i++)
			{
				d[i] = _getch();//读入密码
				if (d[i] == '\r')
				{
					break;
				}
				else if (d[i] == '\b' && i > 0)
				{
					i -= 2;
					printf("\b \b");//按下删除时
				}
				else
				{
					printf("*");
				}
			}
			d[i] = '\0';
			printf("\n");

			if (!strcmp(d, c))//若两次输入密码相等
			{
				strcpy(a.Pass, c);
				fseek(fp, -((int)(sizeof(Ac) - 40)), SEEK_CUR);//将文件指针调回要修改的密码的位置
				fprintf(fp, "%s", a.Pass);
				Sleep(500);
				fclose(fp);
				printf("\t\t更改成功!!");
				Sleep(1000);
				return;
			}
			else
			{
				if (time != 0)
				{
					printf("密码错误！\n\n请重新输入密码！！\n\n您还有%d次机会！！！", time);
					system("pause");
					system("cls");//清屏
					time--;
					continue;
				}
				else
				{
					printf("\n\t\t多次输入错误，即将退出!");
					fclose(fp);
					Sleep(1000);
					return;
				}
			}
		} while (time >= 0);
	}
	else
	{
		printf("\n密码错误！！！\n");
		Sleep(1000);
		system("cls");
		return;
	}
}


