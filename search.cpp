#include"funtion.h"

//查找模块菜单
void searchmenu()
{
	int option = 0;
	printf("\n\t\t\t------------------------------\n\t\t欢迎使用查询系统\n\t\t------------------------------");
	system("color 1F");//设置面板颜色
	while (now)
	{
		system("cls");
		do
		{
			system("cls");
			printf("\n                 ------------------查询菜单-------------------\n");
			printf("\t\t|\t                                      |\n");
			printf("\t\t|\t        ①查询有空余床位的宿舍        |\n");
			printf("\t\t|\t        ②查询学院床位情况            |\n");
			printf("\t\t|\t        ③查询公寓床位情况            |\n");
			printf("\t\t|\t        ④统计空床情况                |\n");
			printf("\t\t|\t        ⑤退出                        |\n");
			printf("\n                 ---------------------------------------------\n");
			printf("\n");
			printf("\t\t请输入选项:  [\t ]\b\b\b\b");
			scanf("%d", &option);//对option进行赋值
		} while (option > 5 || option < 1);//当选择不在界定范围时，结束循环
		searchtran(option);
	}
}


//查询中转模块
void searchtran(int math)
{
	switch (math)
	{
	case 1:
		SearchFreebed();//查询有空余床位的宿舍
		searchmenu();
		break;
	case 2:
		schoolbed();//查询学院床位情况
		searchmenu();//查询模块
		break;
	case 3:
		SearchRidge();//查询公寓床位情况
		searchmenu();
		break;
	case 4:
		CountFreebed();//统计空床
		searchmenu();
		break;
	case 5:
		admmenu();//回到主菜单
		exit(0);//退出
	}
}



/*函数功能：查询有空余床位的宿舍
* 思路：读取文件数据，若有空余床位，则打印出来
*/
void SearchFreebed ()
{
	int num = 0;//num用来计数
	STU* head = file_read();//读取文件数据，保存在链表中
	STU* p =head;//p用来遍历链表
	if (p == NULL)
	{
		printf("读取文件失败！！！\n");
	}
	system("cls");
	printf("\t\t含空余床位的宿舍有：\n");
	printf("\t\t编号\t生活区\t楼栋\t房间号\t房间类别\t床位\t已分配床位\t空余床位\t学院\n");
	while (p != NULL)
	{
		if (p->data.freebed > 0)//若有空余床位，则打印出来
		{
			num++;
			printf("\t\t%d\t %s\t %d\t %d\t  %s\t\t %d\t   %d\t\t %d\t\t%s\n",num, p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
		}
		p = p->next;
	}
	printf("\n\n\t\t按任意键返回上一级菜单！");
	getchar();
	getchar();
}






/*查询学院床位情况
*/
void schoolbed()
{
	char s[30];//记录输入的学院名称
	int n;//n记录选择
	STU* p = file_read();//读取文件数据，保存在链表中
	if (p == NULL)
	{
		printf("文件打开错误！");
		Sleep(1000);
		return;
	}
	system("cls");
	printf("\t\t请输入要查询的学院名称：\n");
	printf("\t\t例如：jsj（计算机学院） zdh（自动化学院）\n\t\t");
	getchar();//吸收回车
	scanf("%s",s);//读取要查询的学院名称
	system("cls");
	do{
		system("cls");
		printf("\t\t请选择要查询的类型：\n\n");
		printf("\t\t①全学院\t\t②男生\t\t③女生\n\n");
		printf("\t\t请输入选项:  [\t ]\b\b\b\b");
		scanf("%d", &n);
		if (n < 1 || n > 3)
		{
			printf("\t\t输入有误，请重新输入");
			Sleep(1000);
		}
	} while (n < 1 || n > 3);
	switch (n)
	{
	case 1:
		all(p,s);//打印全学院住宿信息
		break;
    case 2:
		man(p,s);//打印学院男生信息
		break;
	case 3:
		women(p,s);//打印学院女生信息
		break;

	}

}

void all(STU* p,char s[30])//打印全学院住宿信息
{
	int num = 0;//num用来计数
	int flag = 0;//若flag为1则表示查询到结果
	system("cls");
	printf("\t\t全学院的住宿情况：\n");
	printf("\t\t编号\t生活区\t楼栋\t房间号\t房间类别\t床位\t已分配床位\t空余床位\t学院\n");
	while (p != NULL)
	{
		if (strcmp(s,p->data.school)==0)//若是所选学院，则打印出来
		{
			num++;
			printf("\t\t%d\t %s\t %d\t %d\t  %s\t\t %d\t   %d\t\t %d\t\t%s\n", num, p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
			flag = 1;
		}
		p = p->next;
	}
	if (flag == 0)//若没有查询到
	{
		system("cls");
		printf("\t\t无查询结果！\n");
	}
	printf("\n\n\t\t按任意键返回上一级菜单！");
	getchar();
	getchar();
}


void man(STU* p, char s[30])//打印全学院男生住宿信息
{
	int num = 0;//num用来计数
	int flag = 0;//若flag为1则表示查询到结果
	system("cls");
	printf("\t\t全学院男生的住宿情况：\n");
	printf("\t\t编号\t生活区\t楼栋\t房间号\t房间类别\t床位\t已分配床位\t空余床位\t学院\n");
	while (p != NULL)
	{
		if (strcmp(s, p->data.school) == 0 && strcmp("m",p->data.roomtype)==0)//若是所选学院的男生宿舍，则打印出来
		{
			num++;
			printf("\t\t%d\t %s\t %d\t %d\t  %s\t\t %d\t   %d\t\t %d\t\t%s\n", num, p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
			flag = 1;
		}
		p = p->next;
	}
	if (flag == 0)//若没有查询到
	{
		system("cls");
		printf("\t\t无查询结果！\n");
	}
	printf("\n\n\t\t按任意键返回上一级菜单！");
	getchar();
	getchar();
}



void women(STU* p, char s[30])//打印全学院女生住宿信息
{
	int num = 0;//num用来计数
	int flag = 0;//若flag为1则表示查询到结果
	system("cls");
	printf("\t\t全学院女生的住宿情况：\n");
	printf("\t\t编号\t生活区\t楼栋\t房间号\t房间类别\t床位\t已分配床位\t空余床位\t学院\n");
	while (p != NULL)
	{
		if (strcmp(s, p->data.school) == 0 && strcmp("w", p->data.roomtype) == 0)//若是所选学院的男生宿舍，则打印出来
		{
			num++;
			printf("\t\t%d\t %s\t %d\t %d\t  %s\t\t %d\t   %d\t\t %d\t\t%s\n", num, p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
			flag = 1;
		}
		p = p->next;
	}
	if (flag == 0)//若没有查询到
	{
		system("cls");
		printf("\t\t无查询结果！\n");
	}
	printf("\n\n\t\t按任意键返回上一级菜单！");
	getchar();
	getchar();
}




/*公寓住宿情况查询
* 输入：生活区，起始栋数，末尾栋数
* 输出：所查询的住宿情况
*/
void SearchRidge()
{
	int option;
	system("cls");
	do
	{
		printf("\t\t--------公寓住宿情况查询---------\n");
		printf("\n\t\t请选择查询类型： ①全部公寓查询   ②自定义范围查询   ③单间查询\n");
		printf("\t\t请输入选项:  [\t ]\b\b\b\b");
		scanf("%d", &option);
		if (option < 1 || option>3)
		{
			printf("\t\t输入有误，请重新输入！！！\n");
			Sleep(1000);
			system("cls");
		}
	} while (option < 1 || option>3);
	switch (option)
	{
	case 1:
		SearchRidgeAll();//查看东西两区所有住宿信息
		break;
	case 2:
		SearchRidgeSome();//查看自定义范围宿舍信息
		break;
	case 3:
		SearchOne();//查看单间宿舍
		break;
	}
	
}


void SearchRidgeAll()//查看东西两区所有住宿信息
{
	int num = 0;//num用来计数
	int flag = 0;//若flag为1则表示查询到结果
	system("cls");
	STU* p = file_read();
	printf("\t\t东西区的住宿情况：\n");
	printf("\t\t编号\t生活区\t楼栋\t房间号\t房间类别\t床位\t已分配床位\t空余床位\t学院\n");
	while (p != NULL)
	{
			num++;
			printf("\t\t%d\t %s\t %d\t %d\t  %s\t\t %d\t   %d\t\t %d\t\t%s\n", num, p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
			flag = 1;
		p = p->next;
	}
	if (flag == 0)//若没有查询到
	{
		system("cls");
		printf("\t\t无查询结果！\n");
	}
	printf("\n\n\t\t按任意键返回上一级菜单！");
	getchar();
	getchar();
}



void SearchRidgeSome()//查看自定义范围宿舍信息
{
	int num = 0;//num用来计数
	int flag = 0;//若flag为1则表示查询到结果
	STU* p = file_read();//读取文件
	system("cls");
	char s[20];//记录所要查询的生活区
	int start = 0, end = 0;//记录要查询的栋数

	do
	{
		printf("\t\t请输入要查询的生活区:\n\t\t");
		printf("例: d(东区）、x（西区）\n\t\t");
		scanf("%s", s);
		if (strcmp(s, "d") != 0 && strcmp(s, "x") != 0)//如果输入不规范
		{
			printf("\n\n\t\t输入不规范，请重新输入！！！\n");
			Sleep(1000);
			system("cls");
		}
	} while (strcmp(s, "d") != 0 && strcmp(s, "x") != 0);

	do
	{
		printf("\t\t请输入要查询的栋数\n");
		printf("\n\t\t(若要查询整片生活区，请均输入0)\n");
		printf("\n\t\t请输入开始栋数：");
		scanf("%d", &start);
		printf("\n\t\t请输入结束栋数");
		scanf("%d", &end);
		if (start > end || start < 0 || end < 0)//若输入不规范
		{
			printf("\n\t\t输入有误，请重新输入！！！\n");
			Sleep(1000);
			system("cls");
		}
	} while (start > end || start < 0 || end < 0);

	if (start == 0 && end == 0)//如果均输入0
	{
		system("cls");
		printf("\t\t所选区域的住宿情况：\n");
		printf("\t\t编号\t生活区\t楼栋\t房间号\t房间类别\t床位\t已分配床位\t空余床位\t学院\n");
		while (p != NULL)
		{
			if (strcmp(s, p->data.area) == 0)//若符合生活区，则打印
			{
				num++;
				printf("\t\t%d\t %s\t %d\t %d\t  %s\t\t %d\t   %d\t\t %d\t\t%s\n", num, p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
				flag = 1;
			}
			p = p->next;
		}
		if (flag == 0)//若没有查询到
		{
			system("cls");
			printf("\t\t无查询结果！\n");
		}
		printf("\n\n\t\t按任意键返回上一级菜单！");
		getchar();
		getchar();
	}
	else
	{
		system("cls");
		printf("\t\t所选区域的住宿情况：\n");
		printf("\t\t编号\t生活区\t楼栋\t房间号\t房间类别\t床位\t已分配床位\t空余床位\t学院\n");
		while (p != NULL)
		{
			if (strcmp(s, p->data.area) == 0 && p->data.ridge >= start && p->data.ridge <= end)//若符合生活区，则打印
			{
				num++;
				printf("\t\t%d\t %s\t %d\t %d\t  %s\t\t %d\t   %d\t\t %d\t\t%s\n", num, p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
				flag = 1;
			}
			p = p->next;
		}
		if (flag == 0)//若没有查询到
		{
			system("cls");
			printf("\t\t无查询结果！\n");
		}
		printf("\n\n\t\t按任意键返回上一级菜单！");
		getchar();
		getchar();
	}
}




/*函数作用：查看单间宿舍信息
* 输入：生活区、栋数、房间号
* 输出:住宿信息
* 返回：若找到，返回1，否则返回0
*/
int SearchOne()
{
	char s[20];//记录要查的生活区
	int a, b;//a代表栋数，b代表房间号
	int flag = 0;//标志是否查找到
	STU* p = file_read();
	system("cls");
	do
	{
		printf("\t\t请输入生活区：d(东)/x(西)    ");
		scanf("%s", s);
		printf("\t\t请输入栋数：");
		scanf("%d", &a);
		printf("\t\t请输入房间号：");
		scanf("%d", &b);
		if ((strcmp(s, "d") && strcmp(s, "x")) || a < 0 || b < 0)
		{
			printf("\n\t\t输入有误，请重新输入！！！");
			Sleep(1000);
			system("cls");
		}
	} while ((strcmp(s, "d") && strcmp(s, "x")) || a < 0 || b < 0);

	printf("\t\t所查询的信息为：\n");
	while (p != NULL)
	{
		if (strcmp(s, p->data.area) == 0 && a == p->data.ridge && b == p->data.room)
		{
			printf("\t\t %s\t %d\t %d\t  %s\t\t %d\t   %d\t\t %d\t\t%s\n", p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
			flag = 1;
		}
		p = p->next;
	}
	if (flag == 0)
	{
		system("cls");
		printf("\t\t未找到相关宿舍！\n");
	}
	getchar();
	getchar();
	return flag;
}





/*函数作用：统计空床
* 输入：整数
*/
void CountFreebed()
{
	int option;
	system("cls");
	do
	{
		printf("\t\t-------空床位统计查询界面------\n");
		printf("\n\t\t查询类别：\t①公寓类别查询 \t②学院类别查询\n");
		printf("\t\t请输入选项:  [\t ]\b\b\b\b");
		scanf("%d", &option);
		if (option < 1 || option>2)
		{
			printf("\n选项输入有误，请重新输入！！！\n");
			Sleep(1000);
			system("cls");
		}
	} while (option < 1 || option>2);

	switch (option)
	{
	case 1:
		Countdiy();//自定义区域进行统计
		break;
	case 2:
		Countschool();//学院空床查询
		break;
	}
}


//自定义区域空床统计
void Countdiy()
{
	int sum = 0;//sum记录东西两区总空床数
	int sum1 = 0;//sum1记录所查询区域空床数
	int a[50] = { 0 };//a数组记录所对应栋数的空床位数
	STU* p = file_read();//读取文件
	system("cls");
	char s[20];//记录所要查询的生活区
	int start = 0, end = 0;//记录要查询的栋数

	do
	{
		printf("\t\t请输入要统计的生活区:\n\t\t");
		printf("例: d(东区）、x（西区）\n\t\t");
		scanf("%s", s);
		if (strcmp(s, "d") != 0 && strcmp(s, "x") != 0)//如果输入不规范
		{
			printf("\n\n\t\t输入不规范，请重新输入！！！\n");
			Sleep(1000);
			system("cls");
		}
	} while (strcmp(s, "d") != 0 && strcmp(s, "x") != 0);

	do
	{
		printf("\t\t请输入要统计的栋数\n");
		printf("\n\t\t(若要统计整片生活区，请均输入0)\n");
		printf("\n\t\t请输入开始栋数：");
		scanf("%d", &start);
		printf("\n\t\t请输入结束栋数: ");
		scanf("%d", &end);
		if (start > end || start < 0 || end < 0)//若输入不规范
		{
			printf("\n\t\t输入有误，请重新输入！！！\n");
			Sleep(1000);
			system("cls");
		}
	} while (start > end || start < 0 || end < 0);

	if (start == 0 && end == 0)//如果均输入0
	{
		system("cls");
		printf("\t\t%s区的空床情况：\n",s);
		while (p != NULL)
		{
			if (strcmp(s, p->data.area) == 0 && p->data.freebed > 0)//若符合生活区并有空床
			{
				sum1++;

			}
			if (p->data.freebed > 0)//统计所有空床
			{
				sum++;
			}
			p = p->next;
		}
		printf("\t\t东西两区总空床: %d\n", sum);
		printf("\t\t%s区的总空床数为： %d\n",s, sum1);
		printf("\n\n\t\t按任意键返回上一级菜单！");
		getchar();
		getchar();
	}
	else
	{
		system("cls");
		printf("\t\t所选区域的空床情况：\n");
		while (p != NULL)
		{
			if (p->data.freebed > 0) sum++;//若有空床，sum++
			if (strcmp(s, p->data.area) == 0 && p->data.ridge >= start && p->data.ridge <= end)
			{
				if (p->data.freebed > 0)
				{
					a[p->data.ridge]++;
					sum1++;
    			}
			}
			p = p->next;
		}
		printf("\t\t东西两区总空床: %d\n", sum);
		printf("\t\t所选区域的总空床数为： %d\n",sum1);
		for (i = 1; i < 50; i++)
		{
			if (a[i] > 0)
			{
				printf("\t\t%s %d 的空余床位：%d\n", s, i, a[i]);
			}
		}
		printf("\n\n\t\t按任意键返回上一级菜单！");
		getchar();
		getchar();
	}
}

//查询学院空床
	void Countschool()
{
		char s[30];//记录输入的学院名称
		int sum = 0, sum1 = 0, sum2 = 0;//sum记录学院中空床数，sum1记录男生空床数，sum2记录女生空床数
		STU* p = file_read();//读取文件数据，保存在链表中
		if (p == NULL)
		{
			printf("文件打开错误！");
			Sleep(1000);
			return;
		}
		system("cls");
		printf("\t\t请输入要查询的学院名称：\n");
		printf("\t\t例如：jsj（计算机学院） zdh（自动化学院）\n\t\t");
		getchar();//吸收回车
		scanf("%s", s);//读取要查询的学院名称
		system("cls");
		while (p != NULL)
		{
			if (strcmp(s, p->data.school) == 0 && p->data.freebed > 0)//筛选学院空床
			{
				sum++;
				if (strcmp("m", p->data.roomtype) == 0) sum1++;
				if (strcmp("w", p->data.roomtype) == 0) sum2++;
			}
			p = p->next;
		}
		system("cls");
		printf("\t\t------空床统计信息-----\n\n");
		printf("\t\t%s学院中总空床为：%d\n",s,sum);
		printf("\t\t%s学院中男生宿舍空床为：%d\n", s, sum1);
		printf("\t\t%s学院中女生宿舍空床为：%d\n", s, sum2);
		printf("\n\n\t\t按任意键返回上一级菜单！");
		getchar();
		getchar();
}