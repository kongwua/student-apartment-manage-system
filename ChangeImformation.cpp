#include"funtion.h"

//更改住宿信息模块
void ChangeIm()
{
	int option;//记录选择
	system("cls");
	do
	{
		printf("\t\t----------信息更改界面----------\n");
		printf("\t\t①更改住宿信息\t②删除住宿信息\n");
		printf("\t\t请输入选项:  [\t ]\b\b\b\b");
		scanf("%d", &option);
		if (option < 1 || option>2)
		{
			printf("\t\t输入有误，请重新输入\n");
			Sleep(1000);
			system("cls");
		}
	} while (option < 1 || option>2);
		switch (option)
		{
		case 1:
			ChangeStudent();
			break;
		case 2:
			delateStudent();
			break;
		}
}


/*函数功能：批量更改学生信息
* 无返回值
*/
void ChangeStudent()
{
	int n,j;//n记录循环次数
	char a[20],d[20];//记录生活区
	int b, c;//记录栋数和房间号
	STU* head = file_read();//读取文件数据
	STU* p = NULL;
	STU* p1 = NULL;
	system("cls");
	printf("\t\t请输入要更改的学生数量： ");
	scanf("%d", &n);
	for (j = 0; j < n; j++)
	{
		p = head;
		p1 = NULL;
		system("cls");
		printf("\t\t请输入要更改的学生信息：\n");
		do
		{
			printf("\t\t请输入生活区：d(东)/x(西)    ");
			scanf("%s", a);
			printf("\t\t请输入栋数：");
			scanf("%d", &b);
			printf("\t\t请输入房间号：");
			scanf("%d", &c);
			if ((strcmp(a, "d") && strcmp(a, "x")) || b < 0 || c < 0)
			{
				printf("\n\t\t输入有误，请重新输入！！！");
				Sleep(1000);
				system("cls");
			}
		} while ((strcmp(a, "d") && strcmp(a, "x")) || b < 0 || c < 0);

		printf("\t\t所要更改的信息为：\n");
		int flag = 0;
		while (p != NULL)
		{
			if (strcmp(a, p->data.area) == 0 && b == p->data.ridge && c == p->data.room)
			{
				printf("\t\t %s\t %d\t %d\t  %s\t\t %d\t   %d\t\t %d\t\t%s\n", p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
				flag = 1;
			}
			p1 = p;//保留上一节点地址
			p = p->next;
		}
		if (flag == 0)
		{
			system("cls");
			printf("\n\t\t未找到相关宿舍！\n");
			Sleep(2000);
		}
		else
		{
			printf("\t\t是否更改？ （y/n)  ");
			while (1)
			{
				scanf("%s", d);
				if (strcmp(d, "y") == 0 || strcmp(d, "Y") == 0) break;
				if (strcmp(d, "n") == 0 || strcmp(d, "N") == 0) break;
				//出错处理
				printf("\t\t输入错误，请重新输入！");
			}
			if (strcmp(d, "y") == 0 || strcmp(d, "Y") == 0)
			{
				printf("\t\t请输入更改后的信息：\n");
				printf("\t\t例如：\n");
				printf("\t\t生活区       楼栋 房间号 房间类别      床位 已分配床位 学院  (每个数据用空格隔开,请勿输入中文）\n");
				printf("\t\td(东)/x(西）  1    312  m（男）/w(女)  4     1       jsj(计算机)\n\t\t");
				STU* pi= (STU*)malloc(LEN);//创建新节点保存更改的数据
				scanf("%s %d %d %s %d %d %s", pi->data.area, &pi->data.ridge, &pi->data.room, pi->data.roomtype, &pi->data.bed, &pi->data.rebed, pi->data.school);
				if (pi->data.bed >= pi->data.rebed)//若床位数与已分配床位数合法，计算空余床位
				{
					pi->data.freebed = pi->data.bed - pi->data.rebed;
				}
				else
				{
					printf("床位输入不合法\n");
					free(pi);//释放p1空间
					pi = NULL;//清空指针
					Sleep(1500);
					continue;//退出
				}
				head = delate(a, b, c, head);//删除
				pi->next = head;//链接节点
				head=pi;
				int num = save_txt(head);//将链表写入文件
				free(pi);
				pi = NULL;
				if (num > 0)
				{
					sort(num);
				}
				printf("\t\t更改成功！");
			}

		}
	}
}





/*函数功能：批量删除学生信息
*/
void delateStudent()
{
	int n,j=0;
	char a[20],d[20];//a记录生活区，d记录是否删除
	int b, c;
	system("cls");
	printf("\n\t\t请输入要删除的学生个数：");
	scanf("%d", &n);
	STU* head = file_read();
	STU* p = head;
	for (j = 0; j < n; j++)
	{
		system("cls");
		printf("\t\t请输入要删除的学生信息：\n");
		do
		{
			printf("\t\t请输入生活区：d(东)/x(西)    ");
			scanf("%s", a);
			printf("\t\t请输入栋数：");
			scanf("%d", &b);
			printf("\t\t请输入房间号：");
			scanf("%d", &c);
			if ((strcmp(a, "d") && strcmp(a, "x")) || b < 0 || c < 0)
			{
				printf("\n\t\t输入有误，请重新输入！！！");
				Sleep(1000);
				system("cls");
			}
		} while ((strcmp(a, "d") && strcmp(a, "x")) || b < 0 || c < 0);

		printf("\t\t所要删除的信息为：\n");
		int flag = 0;
		while (p != NULL)
		{
			if (strcmp(a, p->data.area) == 0 && b == p->data.ridge && c == p->data.room)
			{
				printf("\t\t %s\t %d\t %d\t  %s\t\t %d\t   %d\t\t %d\t\t%s\n", p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
				flag = 1;
			}
			p = p->next;
		}
		if (flag == 0)
		{
			printf("\n\t\t未找到相关宿舍！\n");
		}
		else
		{
			
				printf("\t\t是否删除？ （y/n)  ");
				while (1) 
				{
					scanf("%s", d);
					if (strcmp(d, "y") == 0 || strcmp(d, "Y") == 0) break;
					if (strcmp(d, "n") == 0 || strcmp(d, "N") == 0) break;

					printf("\t\t输入错误，请重新输入！");
					Sleep(1500);
				}
			if (strcmp(d, "y") == 0 || strcmp(d, "Y") == 0)
			{
				head = delate(a, b, c, head);//删除
				printf("\t\t删除成功！");
				Sleep(1500);
			}

		}
	}
	if (head != NULL)
	{
		save_txt(head);//将删除后的信息写回文件
	}
}



//删除文件中数据，a为生活区，b为栋数，c为房间号,head为要删除的链表头指针，返回删除后的链表的头指针
STU* delate(char a[20], int b, int c,STU* head)
{
	int num = 0;
	STU* p = head,*p1=NULL;
	STU* temp = NULL;
	if (p == NULL)
	{
		return NULL;
	}
	while (p != NULL)
	{
		if (strcmp(a, p->data.area) == 0 && b == p->data.ridge && p->data.room == c)
		{//若满足删除条件
			if (p==head)//若删除的是头节点
			{
				temp = p;
				head = head->next;
				p = head;
				free(temp);
			}
			else
			{
				temp = p;
				p1->next = p->next;
				free(temp);
				p = p1->next;
			}
		}
		else
		{
			p1 = p;
			p = p->next;
		}
	}
	return head;
}