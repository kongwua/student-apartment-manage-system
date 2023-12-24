#include"funtion.h"






void administor()//管理员登录模块
{
	system("cls");
	Adm guanli;//定义管理员账号信息
	FILE* fp = fopen("Adm.dat", "rb+");
	if (fp == NULL) return;//出错处理
	fread(&guanli, sizeof(Adm), 1, fp);
	char c[20], d[20];//保存输入的账号、密码
	printf("\t\t请输入管理员账号：");
	scanf("%s", &c);
	printf("\n\t\t请输入管理员密码：");
	//scanf("%s", &d);
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
	d[i] = '\0';//只有一个管理员账号，不需要循环读取文件
	if ((0 == strcmp(c, guanli.adm_ZH)) && (strcmp(d, guanli.adm_Pass) == 0))
	{
		admmenu();//若账号密码正确，则进入管理员系统
		return;
	}
	else
	{
		printf("\t\t账号或密码错误！！！");
		Sleep(1000);
		return;
	}
}






void admmenu()//管理员菜单
{
	int option = 0;
	printf("\n\t\t\t------------------------------\n\t\t欢迎使用管理员系统\n\t\t------------------------------");
	system("color 1F");//设置面板颜色
	while (now)
	{
		system("cls");
		do
		{
			system("cls");
			printf("\n                 ------------------管理员菜单-------------------\n");
			printf("\t\t|\t                                        |\n");
			printf("\t\t|\t          ①录入住宿信息                |\n");
			printf("\t\t|\t          ②查询住宿信息                |\n");
			printf("\t\t|\t          ③更改住宿信息                |\n");
			printf("\t\t|\t          ④修改管理员账号              |\n");
			printf("\t\t|\t          ⑤备份                        |\n");
			printf("\t\t|\t          ⑥管理学生账号                |\n");
			printf("\t\t|\t          ⑦退出系统                    |\n");
			printf("\n                 -----------------------------------------------\n");
			printf("\n");
			printf("\t\t请输入选项:  [\t ]\b\b\b\b");
			scanf("%d", &option);//对option进行赋值
		} while (option > 7|| option < 1);//当选择不在界定范围时，结束循环
		admtran(option);
	}
}





//管理系统中转函数
void admtran(int math)
{
	switch (math)
	{
	case 1:
		save();//录入住宿信息
		admmenu();//回到管理员菜单
		break;
	case 2:
		searchmenu();//查询模块
		admmenu();
		break;
	case 3:
		ChangeIm();//更改模块
		admmenu();
		break;
	case 4:
		ChangeZH();//更改管理员账号模块
		admmenu();
		break;
	case 5:
		backup();//备份模块
		admmenu();
		break;
	case 6:
		ManageStu();//管理学生账号模块
		admmenu();
		break;
	case 7:
		menu();//回到主菜单
		exit(0);//退出
	}
}





//录入信息函数
void save()
{
	STU* pointer = NULL;//定义结构体指针保留链表头指针
	STU* pointer1 = NULL;//定义结构体指针保存文件数据链表头指针
	int k;//k表示录入学生的个数
	system("cls");//清屏
	printf("\n\t\t--------------------学生信息录入界面--------------------\n");
	printf("\n\t\t请输入要录入的学生数量：");
	scanf("%d", &k);//对k进行赋值
	pointer = create(k);//输入学生信息，返回一个指针
	if (pointer == NULL)
	{
		return;//出错处理
	}
		pointer1 = file_read();//读取文件中数据
		pointer = check_data(pointer1, pointer);//检查有无重复数据
	    int num = save_txt(pointer);//将链表中的数据录入room.txt中,num表示文件中数据个数
		if (num > 1)
		{
			sort(num);
		}
}





STU* create(int k)//创建动态链表，输入学生信息
{
	system("cls");
	STU* p1 = NULL, * p2 = NULL, * head = NULL;//定义三个指针
	p1 = p2 = (STU*)malloc(LEN);//开创第一个节点用来存放结构体内的数据
	if (p1 != NULL)
	{
		i = 0;
		printf("请输入学生住宿信息：\n");
		printf("例如：\n");
		printf("生活区       楼栋 房间号 房间类别      床位 已分配床位 学院  (每个数据用空格隔开,请勿输入中文，在生活区输入exit退出输入）\n");
		printf("d(东)/x(西）  1    312  m（男）/w(女)  4     1       jsj(计算机)\n");
		while (i < k && p1 != NULL)//避免p1为空指针时导致数据丢失
		{
			scanf("%s %d %d %s %d %d %s", p1->data.area, &p1->data.ridge, &p1->data.room, p1->data.roomtype, &p1->data.bed, &p1->data.rebed, p1->data.school);
			if (strcmp(p1->data.area, "exit") == 0)
			{
				printf("即将退出输入\n");
				Sleep(1000);
				free(p1);
				return NULL;//输入exit退出输入
			}
			if (p1->data.bed >= p1->data.rebed)//若床位数与已分配床位数合法，计算空余床位
			{
				p1->data.freebed = p1->data.bed - p1->data.rebed;
			}
			else
			{
				printf("床位输入不合法,请重新输入\n");
				Sleep(1500);
				continue;//退出
			}
			if (i == 0) head = p1;//记录头指针
			else p2->next = p1;
			p2 = p1;
			p1 = (STU*)malloc(LEN);
			i++;
		}
		free(p1);//释放p1最后申请的空间；
		p2->next = NULL;//链表结尾为空指针
		printf("数据读入成功\n");
	}
	else
	{
		printf("\t\t内存申请出错，请退出重试\n");
	}

	return head;
}



/*函数作用：读取文件数据，建立链表
* 无输入值
* 返回链表的头指针
*/
STU* file_read()
{
	STU* p1 = NULL, * p2 = NULL, * head = NULL;//定义三个指针
	p1 = p2 = (STU*)malloc(LEN);//开创第一个节点用来存放结构体内的数据
	FILE* fp = fopen("room.txt", "rt+");//创建文件指针，读取文件数据
	int k = fgetc(fp);
	if (k==EOF)  return NULL;//若打开的是空文件，返回NULL
	rewind(fp);//让文件指针指回开头
	if (p1 != NULL&& fp != NULL)
	{
		i = 0;//i用来计数
		while (!feof(fp))//当文件未达到结尾时，循环继续
		{
			fscanf(fp, "%s %d %d %s %d %d %d %s\n", p1->data.area, &p1->data.ridge, &p1->data.room, p1->data.roomtype, &p1->data.bed, &p1->data.rebed, &p1->data.freebed, p1->data.school);
			if (i == 0) head = p1;//记录头指针
			else p2->next = p1;
			p2 = p1;
			p1 = (STU*)malloc(LEN);
			i++;
		}
		free(p1);//释放p1最后申请的空间；
		p2->next = NULL;//链表结尾为空指针
	}
	else
	{
		printf("\t\t文件读取错误，请退出重试！\n");
	}
	if(fp!=NULL) fclose(fp);
	return head;
}




/*函数作用：检查是否有重复数据，若有重复，删除head1中重复数据，最后链接两链表
* 输入：两个链表头指针
* 返回值：合并链表的头指针
*/

STU* check_data(STU* head1, STU* head2)
{
	if (head1 == NULL) return head2;//若文件内无数据，返回head2
	STU *p1=head1, *p2=head2,*p1f=NULL,*temp=NULL;//p1用来循环链表1，p2用来循环链表2,p1f用来保存上一节点的地址
	while (p2 != NULL)
	{//链表2(即将存入的数据)内数据循环
		while (p1 != NULL)
		{//链表1（文件中的数据）内数据循环
			if (strcmp(p1->data.area, p2->data.area) == 0 && p1->data.ridge == p2->data.ridge && p1->data.room == p2->data.room)
			{//若生活区、栋数、房间号均相等，则删除该节点
				if (p1 == head1)//如果要删除的是头节点
				{
					temp = p1;
					head1 = head1->next;
					p1 = head1;
					free(temp);
				}
				else//如果要删除的不是头节点
				{
					temp = p1;
					p1f->next = p1->next;
					free(temp);
					p1 = p1f->next;
				}
			}
			else
			{
				p1f = p1;//p1f保留上一节点地址
				p1 = p1->next;
			}
		}
		p2 = p2->next;
	}
	p1f->next = head2;//将两个链表连接起来
	return head1;
}






int save_txt(STU* head)//将链表中的数据录入room.txt中,返回文件中的数据个数
{
	int num = 0;//记录文件中的数据个数
	STU* p = head;
	FILE* fp = fopen("room.txt", "w");//以重写方式打开文件，不能读取
	if (fp == NULL)
	{
		printf("录入文件失败！\n");//出错处理
		return 0;
	}
	while (p != NULL)
	{
		fprintf(fp, "%s %d %d %s %d %d %d %s\n", p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
		p = p->next;
		num++;
	}
	fclose(fp);
	fp = NULL;//清空文件指针
	printf("数据保存成功\n");
	Sleep(2000);
	system("cls");
	return num;
}








/*排序模块
* 作用：读取文件中的数据，用数组进行保存，根据空余床位数由多到少排序
* 输入值：无
* 输出值：无
* 思路：冒泡排序
*/
void sort(int n) 
{
	int j;
	domitory* a = (domitory*)malloc(n * sizeof(domitory));//创建数组保存文件数据
	FILE* fp = fopen("room.txt", "r");
	domitory temp;//temp用来交换
	if (fp == NULL)
	{
		printf("文件打开错误！！！\n");
		Sleep(1000);
		return;
	}
	for (i = 0; i < n; i++)
	{
		//读取文件数据到数组中
		fscanf(fp, "%s %d %d %s %d %d %d %s\n",a[i].area, &a[i].ridge, &a[i].room, a[i].roomtype, &a[i].bed, &a[i].rebed, &a[i].freebed, a[i].school);
	}
	fclose(fp);
	//冒泡排序
	fp = fopen("room.txt", "w");
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i -1; j++)
		{
			if (a[j].freebed < a[j + 1].freebed)//先根据空余床位进行由多到少的排序
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (strcmp(a[j].area, a[j+1].area)>0)//按照生活区进行由多到少的排序
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	
	//写回文件（覆写）
	for (i = 0; i < n; i++)
	{
		fprintf(fp, "%s %d %d %s %d %d %d %s\n", a[i].area, a[i].ridge, a[i].room, a[i].roomtype, a[i].bed, a[i].rebed, a[i].freebed, a[i].school);
	}
	printf("排序成功！！！");
	fclose(fp);
}




/*修改管理员账号信息
*/
void ChangeZH()
{
	system("cls");
	Adm guanli;
	FILE* fp = fopen("Adm.dat","rb+");
	if (fp == NULL)
	{
		printf("\t\t打开文件失败");
		Sleep(1000);
		return;
	}
	char a[20], b[20];
	printf("\t\t请输入新账号：");
	scanf("%s",a);
	printf("\t\t请输入新密码： ");
	scanf("%s",b);
	strcpy(guanli.adm_ZH, a);//复制账号
	strcpy(guanli.adm_Pass, b);//复制密码
	rewind(fp);//指针调回开头
	fwrite(guanli.adm_ZH, sizeof(char), 20, fp);//写入文件
	fwrite(guanli.adm_Pass, sizeof(char), 20, fp);
	fclose(fp);
	printf("\n\t\t修改成功！！！");
	Sleep(1000);
	return;
}


