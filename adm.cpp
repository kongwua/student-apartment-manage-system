#include"funtion.h"






void administor()//����Ա��¼ģ��
{
	system("cls");
	Adm guanli;//�������Ա�˺���Ϣ
	FILE* fp = fopen("Adm.dat", "rb+");
	if (fp == NULL) return;//������
	fread(&guanli, sizeof(Adm), 1, fp);
	char c[20], d[20];//����������˺š�����
	printf("\t\t���������Ա�˺ţ�");
	scanf("%s", &c);
	printf("\n\t\t���������Ա���룺");
	//scanf("%s", &d);
	for (i = 0; i < 20; i++)
	{
		d[i] = _getch();//��������
		if (d[i] == '\r')
		{
			break;
		}
		else if (d[i] == '\b' && i > 0)
		{
			i -= 2;
			printf("\b \b");//����ɾ��ʱ
		}
		else
		{
			printf("*");
		}
	}
	d[i] = '\0';//ֻ��һ������Ա�˺ţ�����Ҫѭ����ȡ�ļ�
	if ((0 == strcmp(c, guanli.adm_ZH)) && (strcmp(d, guanli.adm_Pass) == 0))
	{
		admmenu();//���˺�������ȷ����������Աϵͳ
		return;
	}
	else
	{
		printf("\t\t�˺Ż�������󣡣���");
		Sleep(1000);
		return;
	}
}






void admmenu()//����Ա�˵�
{
	int option = 0;
	printf("\n\t\t\t------------------------------\n\t\t��ӭʹ�ù���Աϵͳ\n\t\t------------------------------");
	system("color 1F");//���������ɫ
	while (now)
	{
		system("cls");
		do
		{
			system("cls");
			printf("\n                 ------------------����Ա�˵�-------------------\n");
			printf("\t\t|\t                                        |\n");
			printf("\t\t|\t          ��¼��ס����Ϣ                |\n");
			printf("\t\t|\t          �ڲ�ѯס����Ϣ                |\n");
			printf("\t\t|\t          �۸���ס����Ϣ                |\n");
			printf("\t\t|\t          ���޸Ĺ���Ա�˺�              |\n");
			printf("\t\t|\t          �ݱ���                        |\n");
			printf("\t\t|\t          �޹���ѧ���˺�                |\n");
			printf("\t\t|\t          ���˳�ϵͳ                    |\n");
			printf("\n                 -----------------------------------------------\n");
			printf("\n");
			printf("\t\t������ѡ��:  [\t ]\b\b\b\b");
			scanf("%d", &option);//��option���и�ֵ
		} while (option > 7|| option < 1);//��ѡ���ڽ綨��Χʱ������ѭ��
		admtran(option);
	}
}





//����ϵͳ��ת����
void admtran(int math)
{
	switch (math)
	{
	case 1:
		save();//¼��ס����Ϣ
		admmenu();//�ص�����Ա�˵�
		break;
	case 2:
		searchmenu();//��ѯģ��
		admmenu();
		break;
	case 3:
		ChangeIm();//����ģ��
		admmenu();
		break;
	case 4:
		ChangeZH();//���Ĺ���Ա�˺�ģ��
		admmenu();
		break;
	case 5:
		backup();//����ģ��
		admmenu();
		break;
	case 6:
		ManageStu();//����ѧ���˺�ģ��
		admmenu();
		break;
	case 7:
		menu();//�ص����˵�
		exit(0);//�˳�
	}
}





//¼����Ϣ����
void save()
{
	STU* pointer = NULL;//����ṹ��ָ�뱣������ͷָ��
	STU* pointer1 = NULL;//����ṹ��ָ�뱣���ļ���������ͷָ��
	int k;//k��ʾ¼��ѧ���ĸ���
	system("cls");//����
	printf("\n\t\t--------------------ѧ����Ϣ¼�����--------------------\n");
	printf("\n\t\t������Ҫ¼���ѧ��������");
	scanf("%d", &k);//��k���и�ֵ
	pointer = create(k);//����ѧ����Ϣ������һ��ָ��
	if (pointer == NULL)
	{
		return;//������
	}
		pointer1 = file_read();//��ȡ�ļ�������
		pointer = check_data(pointer1, pointer);//��������ظ�����
	    int num = save_txt(pointer);//�������е�����¼��room.txt��,num��ʾ�ļ������ݸ���
		if (num > 1)
		{
			sort(num);
		}
}





STU* create(int k)//������̬��������ѧ����Ϣ
{
	system("cls");
	STU* p1 = NULL, * p2 = NULL, * head = NULL;//��������ָ��
	p1 = p2 = (STU*)malloc(LEN);//������һ���ڵ�������Žṹ���ڵ�����
	if (p1 != NULL)
	{
		i = 0;
		printf("������ѧ��ס����Ϣ��\n");
		printf("���磺\n");
		printf("������       ¥�� ����� �������      ��λ �ѷ��䴲λ ѧԺ  (ÿ�������ÿո����,�����������ģ�������������exit�˳����룩\n");
		printf("d(��)/x(����  1    312  m���У�/w(Ů)  4     1       jsj(�����)\n");
		while (i < k && p1 != NULL)//����p1Ϊ��ָ��ʱ�������ݶ�ʧ
		{
			scanf("%s %d %d %s %d %d %s", p1->data.area, &p1->data.ridge, &p1->data.room, p1->data.roomtype, &p1->data.bed, &p1->data.rebed, p1->data.school);
			if (strcmp(p1->data.area, "exit") == 0)
			{
				printf("�����˳�����\n");
				Sleep(1000);
				free(p1);
				return NULL;//����exit�˳�����
			}
			if (p1->data.bed >= p1->data.rebed)//����λ�����ѷ��䴲λ���Ϸ���������ലλ
			{
				p1->data.freebed = p1->data.bed - p1->data.rebed;
			}
			else
			{
				printf("��λ���벻�Ϸ�,����������\n");
				Sleep(1500);
				continue;//�˳�
			}
			if (i == 0) head = p1;//��¼ͷָ��
			else p2->next = p1;
			p2 = p1;
			p1 = (STU*)malloc(LEN);
			i++;
		}
		free(p1);//�ͷ�p1�������Ŀռ䣻
		p2->next = NULL;//�����βΪ��ָ��
		printf("���ݶ���ɹ�\n");
	}
	else
	{
		printf("\t\t�ڴ�����������˳�����\n");
	}

	return head;
}



/*�������ã���ȡ�ļ����ݣ���������
* ������ֵ
* ���������ͷָ��
*/
STU* file_read()
{
	STU* p1 = NULL, * p2 = NULL, * head = NULL;//��������ָ��
	p1 = p2 = (STU*)malloc(LEN);//������һ���ڵ�������Žṹ���ڵ�����
	FILE* fp = fopen("room.txt", "rt+");//�����ļ�ָ�룬��ȡ�ļ�����
	int k = fgetc(fp);
	if (k==EOF)  return NULL;//���򿪵��ǿ��ļ�������NULL
	rewind(fp);//���ļ�ָ��ָ�ؿ�ͷ
	if (p1 != NULL&& fp != NULL)
	{
		i = 0;//i��������
		while (!feof(fp))//���ļ�δ�ﵽ��βʱ��ѭ������
		{
			fscanf(fp, "%s %d %d %s %d %d %d %s\n", p1->data.area, &p1->data.ridge, &p1->data.room, p1->data.roomtype, &p1->data.bed, &p1->data.rebed, &p1->data.freebed, p1->data.school);
			if (i == 0) head = p1;//��¼ͷָ��
			else p2->next = p1;
			p2 = p1;
			p1 = (STU*)malloc(LEN);
			i++;
		}
		free(p1);//�ͷ�p1�������Ŀռ䣻
		p2->next = NULL;//�����βΪ��ָ��
	}
	else
	{
		printf("\t\t�ļ���ȡ�������˳����ԣ�\n");
	}
	if(fp!=NULL) fclose(fp);
	return head;
}




/*�������ã�����Ƿ����ظ����ݣ������ظ���ɾ��head1���ظ����ݣ��������������
* ���룺��������ͷָ��
* ����ֵ���ϲ������ͷָ��
*/

STU* check_data(STU* head1, STU* head2)
{
	if (head1 == NULL) return head2;//���ļ��������ݣ�����head2
	STU *p1=head1, *p2=head2,*p1f=NULL,*temp=NULL;//p1����ѭ������1��p2����ѭ������2,p1f����������һ�ڵ�ĵ�ַ
	while (p2 != NULL)
	{//����2(�������������)������ѭ��
		while (p1 != NULL)
		{//����1���ļ��е����ݣ�������ѭ��
			if (strcmp(p1->data.area, p2->data.area) == 0 && p1->data.ridge == p2->data.ridge && p1->data.room == p2->data.room)
			{//��������������������ž���ȣ���ɾ���ýڵ�
				if (p1 == head1)//���Ҫɾ������ͷ�ڵ�
				{
					temp = p1;
					head1 = head1->next;
					p1 = head1;
					free(temp);
				}
				else//���Ҫɾ���Ĳ���ͷ�ڵ�
				{
					temp = p1;
					p1f->next = p1->next;
					free(temp);
					p1 = p1f->next;
				}
			}
			else
			{
				p1f = p1;//p1f������һ�ڵ��ַ
				p1 = p1->next;
			}
		}
		p2 = p2->next;
	}
	p1f->next = head2;//������������������
	return head1;
}






int save_txt(STU* head)//�������е�����¼��room.txt��,�����ļ��е����ݸ���
{
	int num = 0;//��¼�ļ��е����ݸ���
	STU* p = head;
	FILE* fp = fopen("room.txt", "w");//����д��ʽ���ļ������ܶ�ȡ
	if (fp == NULL)
	{
		printf("¼���ļ�ʧ�ܣ�\n");//������
		return 0;
	}
	while (p != NULL)
	{
		fprintf(fp, "%s %d %d %s %d %d %d %s\n", p->data.area, p->data.ridge, p->data.room, p->data.roomtype, p->data.bed, p->data.rebed, p->data.freebed, p->data.school);
		p = p->next;
		num++;
	}
	fclose(fp);
	fp = NULL;//����ļ�ָ��
	printf("���ݱ���ɹ�\n");
	Sleep(2000);
	system("cls");
	return num;
}








/*����ģ��
* ���ã���ȡ�ļ��е����ݣ���������б��棬���ݿ��ലλ���ɶൽ������
* ����ֵ����
* ���ֵ����
* ˼·��ð������
*/
void sort(int n) 
{
	int j;
	domitory* a = (domitory*)malloc(n * sizeof(domitory));//�������鱣���ļ�����
	FILE* fp = fopen("room.txt", "r");
	domitory temp;//temp��������
	if (fp == NULL)
	{
		printf("�ļ��򿪴��󣡣���\n");
		Sleep(1000);
		return;
	}
	for (i = 0; i < n; i++)
	{
		//��ȡ�ļ����ݵ�������
		fscanf(fp, "%s %d %d %s %d %d %d %s\n",a[i].area, &a[i].ridge, &a[i].room, a[i].roomtype, &a[i].bed, &a[i].rebed, &a[i].freebed, a[i].school);
	}
	fclose(fp);
	//ð������
	fp = fopen("room.txt", "w");
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i -1; j++)
		{
			if (a[j].freebed < a[j + 1].freebed)//�ȸ��ݿ��ലλ�����ɶൽ�ٵ�����
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
			if (strcmp(a[j].area, a[j+1].area)>0)//���������������ɶൽ�ٵ�����
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	
	//д���ļ�����д��
	for (i = 0; i < n; i++)
	{
		fprintf(fp, "%s %d %d %s %d %d %d %s\n", a[i].area, a[i].ridge, a[i].room, a[i].roomtype, a[i].bed, a[i].rebed, a[i].freebed, a[i].school);
	}
	printf("����ɹ�������");
	fclose(fp);
}




/*�޸Ĺ���Ա�˺���Ϣ
*/
void ChangeZH()
{
	system("cls");
	Adm guanli;
	FILE* fp = fopen("Adm.dat","rb+");
	if (fp == NULL)
	{
		printf("\t\t���ļ�ʧ��");
		Sleep(1000);
		return;
	}
	char a[20], b[20];
	printf("\t\t���������˺ţ�");
	scanf("%s",a);
	printf("\t\t�����������룺 ");
	scanf("%s",b);
	strcpy(guanli.adm_ZH, a);//�����˺�
	strcpy(guanli.adm_Pass, b);//��������
	rewind(fp);//ָ����ؿ�ͷ
	fwrite(guanli.adm_ZH, sizeof(char), 20, fp);//д���ļ�
	fwrite(guanli.adm_Pass, sizeof(char), 20, fp);
	fclose(fp);
	printf("\n\t\t�޸ĳɹ�������");
	Sleep(1000);
	return;
}


