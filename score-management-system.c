/*
(1)	ѧ����Ϣ������ѧ�š����������Ƴɼ���������4�ſγ̣���
(2)	��ͨ���˵����г���
(3)	��Ϣ¼�롪��������ѧ����Ϣ��Ҫ��ѧ�Ų����ظ���
(4)	��Ϣ��������������ѧ���������Ϣ��ѧ�š����������Ƴɼ����ܷ֡�ƽ���ֵȣ���
(5) 	��Ϣ�޸ġ����޸�����ѧ�Ÿ��Ƴɼ��ȣ�
(6)	��Ϣɾ�������ܰ��������ѧ��ɾ����Ӧѧ����Ϣ��
(7)	��Ϣ��ѯ�����ܰ��ն��ַ�ʽ��ѯѧ����Ϣ��ѧ�š����������Ƴɼ�������ѧ����
(8)	��Ϣ���򡪡������ܷ��ɸߵ��ͽ�������
(9)	��Ϣͳ�ơ�����ͳ��ÿ��ѧ�����ܷ֡�ƽ���֣�������߷֡���ͷ֡������������ȡ�
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CH 20 // ����ַ�
#define N 100 // ѧ����������

//ѧ���Ľṹ��
typedef struct student {
	char name[CH];    //����
	char no[CH];      //ѧ��
	float math;       //�����ɼ�
	float English;    //Ӣ��ɼ�
	float physics;    //����ɼ�
	float C_language; //C���Գɼ�
	float Average;    //ƽ������
	float S_all;      //�ܷ���
}student;
student s[N];         //ѧ������
int num;              //ѧ������


//��������
void welcome();              //��ӭ����
void meun();                 //�˵�����
void read_from_file();       //���ļ��ж�ȡѧ������Ϣ
void write_to_file();        //���ļ���д��ѧ������Ϣ
void Add();                  //���ѧ����Ϣ
void Show();                 //��ʾѧ����Ϣ
void Change_information();   //�޸�ѧ����Ϣ
void Change_information1();  //��ѧ���޸�
void Change_information2();  //�������޸�
void Delete();		         //ɾ��ѧ����Ϣ
void Delete1();              //��ѧ��ɾ��
void Delete2();              //������ɾ��
void Search();		         //��ѯѧ���ɼ�
void Search1();              //��ѧ�Ų�ѯ
void Search2();              //��������ѯ
void Sort();		         //�ɼ��������
void Sort1();		         //�����������
void Sort2();		         //Ӣ���������
void Sort3();		         //�����������
void Sort4();		         // C�����������
void Sort5();		         //�����������
void Secede();		         //�˳���ѯ


void main() {
	int choose = 0;   //��ʼ���������������Ϊ0
	num = 0;          //��ʼ��ѧ������Ϊ0
	read_from_file(); //��ȡ�ļ�
	welcome();
	meun();
	scanf("%d", &choose);
	printf("\n");
	while (choose>0 && choose<8) {
		switch (choose) {
		case 1:Add();system("pause");break;
		case 2:Show();system("pause");break;
		case 3:Change_information();system("pause");break;
		case 4:Delete();system("pause");break;
		case 5:Search();system("pause");break;
		case 6:Sort();system("pause");break;
		case 7:Secede();system("pause");goto end;
		}

		printf("\n");
		meun();
		scanf("%d", &choose);
		printf("\n");
	}
end:write_to_file();//д���ļ�
}


//����������
//��ӭ����
void welcome() {
	printf("\n\n");
	printf("\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\n\n\n");
	printf("\t\t�q�T�T�T�T�T�T�T�T�T�T�T�T�T��ѧ���ɼ�����ϵͳ���T�T�T�T�T�T�T�T�T�T�T�T�T�r\n");
	printf("\t\t�U* * * * * * * * * * *  * * * * * * * * * * *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*     --------  �� Ң  �� ��  --------     *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*          ��ӭʹ�øóɼ�����ϵͳ          *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*                WELCOME������             *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*               �밴�س�������             *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*                  ----                    *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U* * * * * * * * * * *  * * * * * * * * * * *�U\n");
	printf("\t\t�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
	printf("\n\n\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\n\n\n");
	getchar();
}


//�˵�����
void meun() {
	system("cls"); //��Ļ���
	printf("\n\n\n\n\n");
	printf("\t\t�q�T�T�T�T�T�T�T�T�T�T�T�T�T�T��ѧ���ɼ�����ϵͳ���T�T�T�T�T�T�T�T�T�T�T�T�r\n");
	printf("\t\t�U* * * * * * * * * * *  * * * * * * * * * * *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*     --------  �� Ң  �� ��  --------     *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*     --------    �� �� ��    --------     *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*             1. ¼��ѧ������              *�U\n");
	printf("\t\t�U*             2. ��ʾѧ������              *�U\n");
	printf("\t\t�U*             3. �޸�ѧ������              *�U\n");
	printf("\t\t�U*             4. ɾ��ѧ������              *�U\n");
	printf("\t\t�U*             5. ��ѯ�ɼ�����              *�U\n");
	printf("\t\t�U*             6. �����������              *�U\n");
	printf("\t\t�U*             7. �˳�����ϵͳ              *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U* * * * * * * * * * *  * * * * * * * * * * *�U\n");
	printf("\t\t�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
	printf("\t\t \1\tע:������Ϊ����������������**�Ա��ڶ���\n");
	printf("\t\t \2\t��ѡ��˵�ѡ��(1-7):");
}


//���ļ��ж�ȡѧ������Ϣ
void read_from_file() {
	FILE *fp;
	int i = 0;
	fp = fopen("data.db", "rb");
	if (!fp) {
		printf("���ļ�data.dbʧ��!\n");
		return;
	}
	fread(&num, 1, sizeof(num), fp); //�ȶ�ȡѧ���ĸ���
	for (i = 0;i<num;i++)
		fread(&s[i], 1, sizeof(student), fp); //��ȡÿ��ѧ������Ϣ��ŵ��ṹ��
	fclose(fp);//�ر��ļ�
	printf("��ȡѧ����Ϣ���!");
}


//���ļ���д��ѧ������Ϣ
void write_to_file() {
	FILE *fp;
	int i = 0;
	fp = fopen("data.db","wb+");
	if (!fp) {
		printf("���ļ�data.dbʧ��!\n");
		return;
	}
	fwrite(&num, 1, sizeof(num), fp); //��д��ѧ���ĸ���
	for (i = 0;i<num;i++) fwrite(&s[i], 1, sizeof(student), fp); //д��ÿ��ѧ������Ϣ
	fclose(fp);//�ر��ļ�
	printf("д��ѧ����Ϣ���!\n");
}


//���ѧ����Ϣ
void Add() {
	int i = num;
	printf("����������:"); scanf("%s", s[i].name);
	printf("������ѧ��:"); scanf("%s", s[i].no);
	printf("����������ɼ�:"); scanf("%f", &s[i].math);
	printf("������Ӣ��ɼ�:"); scanf("%f", &s[i].English);
	printf("����������ɼ�:"); scanf("%f", &s[i].physics);
	printf("������C���Գɼ�:"); scanf("%f", &s[i].C_language);
	s[i].S_all = s[i].math + s[i].English + s[i].physics + s[i].C_language; //������ܷ���
	s[i].Average = s[i].S_all / 4; //�����ƽ����
	num++;
}


//��ʾѧ����Ϣ
void Show() {
	int i = 0;
	printf("%s%13s%15s%15s%15s%15s%15s%15s\n", "����", "ѧ��", "����", "Ӣ��", "����", "C��", "�ܷ�", "����");
	for (i = 0;i<num;i++) printf("%s%11s%15.2f%15.2f%15.2f%15.2f%15.2f%15.2f\n", s[i].name, s[i].no, s[i].math, s[i].English, s[i].physics, s[i].C_language, s[i].S_all, s[i].Average);
}


//�޸�ѧ����Ϣ
void Change_information() {
	int choice = 1;
	printf("���������밴��ʲô�޸�\n1.ѧ�ţ�2.����\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:Change_information1();system("pause");break;
	case 2:Change_information2();system("pause");break;
	default:printf("û�и�ѡ�");break;
	}
}


//�޸�ѧ����Ϣ
void Change_information1() {
	int i = 0;
	char no[CH]; //ѧ��
	printf("��������Ҫ�޸ĵ�ѧ��ѧ��:");
	scanf("%s", no);
	for (i = 0;i<num;i++)//���ҵ���ѧ�Ŷ�Ӧ�����
		if (strcmp(s[i].no, no) == 0) {
			printf("����������:"); scanf("%s", s[i].name);
			printf("������ѧ��:"); scanf("%s", s[i].no);
			printf("����������ɼ�:"); scanf("%f", &s[i].math);
			printf("������Ӣ��ɼ�:"); scanf("%f", &s[i].English);
			printf("����������ɼ�:"); scanf("%f", &s[i].physics);
			printf("������C���Գɼ�:"); scanf("%f", &s[i].C_language);
			s[i].S_all = s[i].math + s[i].English + s[i].physics + s[i].C_language; //������ܷ���
			s[i].Average = s[i].S_all / 4; //�����ƽ����
			printf("%s%s", no, "ѧ��ͬѧ�������Ѹı�!\n");
			return;
		}
	printf("%s%s", no, "ѧ��ͬѧû������!\n");
}



//�������޸�ѧ����Ϣ
void Change_information2() {
	int i = 0;
	char name[CH];//����
	printf("��������Ҫ�޸ĵ�ѧ������:");
	scanf("%s", name);
	for (i = 0;i<num;i++)//���ҵ���������Ӧ�����
		if (strcmp(s[i].name, name) == 0) {
			printf("����������:"); scanf("%s", s[i].name);
			printf("������ѧ��:"); scanf("%s", s[i].no);
			printf("����������ɼ�:"); scanf("%f", &s[i].math);
			printf("������Ӣ��ɼ�:"); scanf("%f", &s[i].English);
			printf("����������ɼ�:"); scanf("%f", &s[i].physics);
			printf("������C���Գɼ�:"); scanf("%f", &s[i].C_language);
			s[i].S_all = s[i].math + s[i].English + s[i].physics + s[i].C_language; //������ܷ���
			s[i].Average = s[i].S_all / 4; //�����ƽ����
			printf("%s%s", name, "����ͬѧ�������Ѹı�!\n");
			return;
		}
	printf("%s%s", name, "����ͬѧû������!\n");
}



//ɾ��ѧ����Ϣ
void Delete() {
	int choice = 1;
	printf("���������밴��ʲôɾ��\n1.ѧ�ţ�2.����\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:Delete1();system("pause");break;
	case 2:Delete2();system("pause");break;
	default:printf("û�и�ѡ�");break;
	}
}


//��ѧ��ɾ��ѧ����Ϣ
void Delete1() {
	int i = 0, j = 0;
	char no[CH]; //ѧ��
	printf("��������Ҫɾ����ѧ��ѧ��:");
	scanf("%s", no);
	for (i = 0;i<num;i++)//���ҵ���ѧ�Ŷ�Ӧ�����
		if (strcmp(s[i].no, no) == 0 ) {
			for (j = i;j<num - 1;j++) s[j] = s[j + 1];
			num--; //�������� 1
			printf("%s%s", no, "ѧ��ͬѧ��������ɾ��!\n");
			return;
		}
	printf("%s%s",no,"ѧ��ͬѧû������!\n");
}



//������ɾ��ѧ����Ϣ
void Delete2() {
	int i = 0, j = 0;
	char name[CH];//����
	printf("��������Ҫɾ����ѧ������:");
	scanf("%s", name);
	for (i = 0;i<num;i++)//���ҵ���������Ӧ�����
		if (strcmp(s[i].name, name) == 0) {
			for (j = i;j<num - 1;j++) s[j] = s[j + 1];
			num--; //�������� 1
			printf("%s%s", name, "����ͬѧ��������ɾ��!\n");
			return;
		}
	printf("%s%s", name, "����ͬѧû������!\n");
}



//��������
void Search() {
	int choice = 1;
	printf("���������밴��ʲô����\n1.ѧ�ţ�2.����\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:Search1();system("pause");break;
	case 2:Search2();system("pause");break;
	default:printf("û�и�ѡ�");break;
	}
}


//��ѧ�Ų�ѯѧ���ɼ�
void Search1() {
	int i = 0;
	char no[CH]; //ѧ��
	printf("��������Ҫ��ѯ��ѧ��ѧ��:");
	scanf("%s", no);
	for (i = 0;i<num;i++)//���ҵ���ѧ�Ŷ�Ӧ�����
		if (strcmp(s[i].no, no) == 0) {
			printf("%s\t%8s\t%8s\t%8s\t%6s\t%14s\t%12s\t%12s\n", "����", "ѧ��", "����", "Ӣ��", "����", "C����", "�ܷ�", "����");
			printf("%s%11s%15.2f%15.2f%15.2f%15.2f%15.2f%15.2f\n", s[i].name, s[i].no, s[i].math, s[i].English, s[i].physics, s[i].C_language, s[i].S_all, s[i].Average);
			return;
		}
	printf("%s%s", no, "ѧ��ͬѧû������!\n");
}

//��������ѯѧ���ɼ�
void Search2() {
	int i = 0;
	char name[CH];//����
	printf("��������Ҫ��ѯ��ѧ������:");
	scanf("%s", name);
	for (i = 0;i<num;i++)//���ҵ���������Ӧ�����
		if (strcmp(s[i].name, name) == 0) {
			printf("%s\t%8s\t%8s\t%8s\t%6s\t%14s\t%12s\t%12s\n", "����", "ѧ��", "����", "Ӣ��", "����", "C����", "�ܷ�", "����");
			printf("%s%11s%15.2f%15.2f%15.2f%15.2f%15.2f%15.2f\n", s[i].name, s[i].no, s[i].math, s[i].English, s[i].physics, s[i].C_language, s[i].S_all, s[i].Average);
			return;
		}
	printf("%s%s",name,"����ͬѧû������!\n");
}


//�ɼ��������
void Sort() {
	int choice = 5;
	printf("���������밴��ʲô����\n1.������2.Ӣ�3.����4.C���ԣ�5.ƽ����\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:Sort1();system("pause");break;
	case 2:Sort2();system("pause");break;
	case 3:Sort3();system("pause");break;
	case 4:Sort4();system("pause");break;
	case 5:Sort5();system("pause");break;
	default:printf("û�и�ѡ�");break;
	}
}


//�ø����ɼ���������
void Sort1() {
	int i = 0, j = 0;
	student t;//�������򽻻�����ʱ����
	student s1[N]; //ѧ������,�����������ʱ����
	for (i = 0;i<num;i++)
		s1[i] = s[i];
	for (i = 0;i<num;i++)
		for (j = i + 1;j<num;j++)
			if (s1[i].math<s1[j].math) {
				t = s1[i];
				s1[i] = s1[j];
				s1[j] = t;
			}
	printf("%s\t%8s\t%8s\t%8s\t%6s\t%14s\t%12s\t%12s\n", "����", "ѧ��", "����", "Ӣ��", "����", "C����", "�ܷ�", "����");
	for (i = 0;i<num;i++) printf("%s%10s%15.2f%15.2f%15.2f%15.2f%15.2f%15.2f\n", s1[i].name, s1[i].no, s1[i].math, s1[i].English, s1[i].physics, s1[i].C_language, s1[i].S_all, s1[i].Average);
}


//��Ӣ��ɼ���������
void Sort2() {
	int i = 0, j = 0;
	student t;//�������򽻻�����ʱ����
	student s1[N]; //ѧ������,�����������ʱ����
	for (i = 0;i<num;i++)
		s1[i] = s[i];
	for (i = 0;i<num;i++)
		for (j = i + 1;j<num;j++)
			if (s1[i].English<s1[j].English) {
				t = s1[i];
				s1[i] = s1[j];
				s1[j] = t;
			}
	printf("%s\t%8s\t%8s\t%8s\t%6s\t%14s\t%12s\t%12s\n", "����", "ѧ��", "����", "Ӣ��", "����", "C����", "�ܷ�", "����");
	for (i = 0;i<num;i++) printf("%s%10s%15.2f%15.2f%15.2f%15.2f%15.2f%15.2f\n", s1[i].name, s1[i].no, s1[i].math, s1[i].English, s1[i].physics, s1[i].C_language, s1[i].S_all, s1[i].Average);
}


//������ɼ���������
void Sort3() {
	int i = 0, j = 0;
	student t;//�������򽻻�����ʱ����
	student s1[N]; //ѧ������,�����������ʱ����
	for (i = 0;i<num;i++)
		s1[i] = s[i];
	for (i = 0;i<num;i++)
		for (j = i + 1;j<num;j++)
			if (s1[i].physics<s1[j].physics) {
				t = s1[i];
				s1[i] = s1[j];
				s1[j] = t;
			}
	printf("%s\t%8s\t%8s\t%8s\t%6s\t%14s\t%12s\t%12s\n", "����", "ѧ��", "����", "Ӣ��", "����", "C����", "�ܷ�", "����");
	for (i = 0;i<num;i++) printf("%s%10s%15.2f%15.2f%15.2f%15.2f%15.2f%15.2f\n", s1[i].name, s1[i].no, s1[i].math, s1[i].English, s1[i].physics, s1[i].C_language, s1[i].S_all, s1[i].Average);
}


//��C���Գɼ���������
void Sort4() {
	int i = 0, j = 0;
	student t;//�������򽻻�����ʱ����
	student s1[N]; //ѧ������,�����������ʱ����
	for (i = 0;i<num;i++)
		s1[i] = s[i];
	for (i = 0;i<num;i++)
		for (j = i + 1;j<num;j++)
			if (s1[i].C_language<s1[j].C_language) {
				t = s1[i];
				s1[i] = s1[j];
				s1[j] = t;
			}
	printf("%s\t%8s\t%8s\t%8s\t%6s\t%14s\t%12s\t%12s\n", "����", "ѧ��", "����", "Ӣ��", "����", "C����", "�ܷ�", "����");
	for (i = 0;i<num;i++) printf("%s%10s%15.2f%15.2f%15.2f%15.2f%15.2f%15.2f\n", s1[i].name, s1[i].no, s1[i].math, s1[i].English, s1[i].physics, s1[i].C_language, s1[i].S_all, s1[i].Average);
}


//��ƽ��ֵ��������
void Sort5() {
	int i = 0, j = 0;
	student t;//�������򽻻�����ʱ����
	student s1[N]; //ѧ������,�����������ʱ����
	for (i = 0;i<num;i++)
		s1[i] = s[i];
	for (i = 0;i<num;i++)
		for (j = i + 1;j<num;j++)
			if (s1[i].Average<s1[j].Average) {
				t = s1[i];
				s1[i] = s1[j];
				s1[j] = t;
			}
	printf("%s\t%8s\t%8s\t%8s\t%6s\t%14s\t%12s\t%12s\n", "����", "ѧ��", "����", "Ӣ��", "����", "C����", "�ܷ�", "����");
	for (i = 0;i<num;i++) printf("%s%10s%15.2f%15.2f%15.2f%15.2f%15.2f%15.2f\n", s1[i].name, s1[i].no, s1[i].math, s1[i].English, s1[i].physics, s1[i].C_language, s1[i].S_all, s1[i].Average);
}


//�˳���ѯ
void Secede() {
	system("cls"); //��Ļ���
	printf("\n\n");
	printf("\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\n\n\n");
	printf("\t\t�q�T�T�T�T�T�T�T�T�T�T�T�T�T��ѧ���ɼ�����ϵͳ���T�T�T�T�T�T�T�T�T�T�T�T�T�r\n");
	printf("\t\t�U* * * * * * * * * * *  * * * * * * * * * * *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*     --------  �� Ң  �� ��  --------     *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*        ��ӭ�ٴ�ʹ�øóɼ�����ϵͳ        *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*            WELCOME  TO  BACK��           *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*                �ټ���������              *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*                ��^_^��/~~                *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U*                                          *�U\n");
	printf("\t\t�U* * * * * * * * * * *  * * * * * * * * * * *�U\n");
	printf("\t\t�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");
	printf("\n\n\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\n\n\n");
}
