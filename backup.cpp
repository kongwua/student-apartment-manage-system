#include "funtion.h"

//备份模块

void backup()
{
	int option;
	do
	{
		system("cls");
		printf("\n\t\t①存入备份   ②读取备份\n");
		printf("\t\t请输入选项:  [\t ]\b\b\b\b");
		scanf("%d", &option);
		if (option < 1 || option>2)
		{
			printf("\t\t输入有误，请重新输入\n");
			Sleep(1500);
			system("cls");
		}
	} while (option < 1 || option>2);
	switch (option)
	{
	case 1:
		backsave1();
		break;
	case 2:
		backupsave2();
		break;
	}
}


/*文件复制函数
* 将room文件的内容复制到backup文件中
*/
void backsave1()
{
	STU* p = file_read();//读取文件内容
	FILE* fp = fopen("backup.txt", "w");//以重写方式打开文件，不能读取
	if (fp == NULL)
	{
		printf("录入文件失败！\n");//出错处理
		return ;
	}
	while (p != NULL)
	{
		fprintf(fp, "%s %d %d %s %d %d %d %s\n", p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
		p = p->next;
	}
	fclose(fp);
	fp = NULL;//清空文件指针
	printf("\t\t数据备份成功\n");
	Sleep(2000);
	system("cls");
}


//将backup文件中的数据写入room文件中
void backupsave2()
{
	//读取backup文件内容
	STU* p1 = NULL, * p2 = NULL, * head = NULL;//定义三个指针
	p1 = p2 = (STU*)malloc(LEN);//开创第一个节点用来存放结构体内的数据
	FILE* fp = fopen("backup.txt", "rt+");//创建文件指针，读取文件数据
	int k = fgetc(fp);
	if (k == EOF)  return ;//若打开的是空文件，返回NULL
	rewind(fp);//让文件指针指回开头
	if (p1 != NULL && fp != NULL)
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
	if (fp != NULL) fclose(fp);

   //写入room文件
	STU* p = head;
	FILE* fg = fopen("room.txt", "w");//以重写方式打开文件，不能读取
	if (fg == NULL)
	{
		printf("录入文件失败！\n");//出错处理
		return;
	}
	while (p != NULL)
	{
		fprintf(fg, "%s %d %d %s %d %d %d %s\n", p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
		p = p->next;
	}
	fclose(fg);
	fg = NULL;//清空文件指针
	printf("\t\t备份读取成功\n");
	Sleep(2000);
	system("cls");
}