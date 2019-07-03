/*
(1)	学生信息包括：学号、姓名、各科成绩（不少于4门课程）；
(2)	能通过菜单运行程序；
(3)	信息录入——能输入学生信息，要求学号不能重复；
(4)	信息浏览——输出所有学生的相关信息（学号、姓名、各科成绩、总分、平均分等）；
(5) 	信息修改——修改姓名学号各科成绩等；
(6)	信息删除——能按照输入的学号删除对应学生信息；
(7)	信息查询——能按照多种方式查询学生信息：学号、姓名、各科成绩不及格学生；
(8)	信息排序——按照总分由高到低进行排序；
(9)	信息统计——能统计每个学生的总分、平均分，各科最高分、最低分、不及格人数等。
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CH 20 // 最大字符
#define N 100 // 学生的最大个数

//学生的结构体
typedef struct student {
	char name[CH];    //姓名
	char no[CH];      //学号
	float math;       //高数成绩
	float English;    //英语成绩
	float physics;    //物理成绩
	float C_language; //C语言成绩
	float Average;    //平均分数
	float S_all;      //总分数
}student;
student s[N];         //学生数组
int num;              //学生个数


//函数声明
void welcome();              //欢迎界面
void meun();                 //菜单界面
void read_from_file();       //从文件中读取学生的信息
void write_to_file();        //向文件中写入学生的信息
void Add();                  //添加学生信息
void Show();                 //显示学生信息
void Change_information();   //修改学生信息
void Change_information1();  //按学号修改
void Change_information2();  //按姓名修改
void Delete();		         //删除学生信息
void Delete1();              //按学号删除
void Delete2();              //按姓名删除
void Search();		         //查询学生成绩
void Search1();              //按学号查询
void Search2();              //按姓名查询
void Sort();		         //成绩排序输出
void Sort1();		         //高数排序输出
void Sort2();		         //英语排序输出
void Sort3();		         //物理排序输出
void Sort4();		         // C语言排序输出
void Sort5();		         //均分排序输出
void Secede();		         //退出查询


void main() {
	int choose = 0;   //初始化键盘输入的数字为0
	num = 0;          //初始化学生个数为0
	read_from_file(); //读取文件
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
end:write_to_file();//写入文件
}


//程序辅助函数
//欢迎界面
void welcome() {
	printf("\n\n");
	printf("\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\n\n\n");
	printf("\t\t╭═════════════┤学生成绩管理系统├═════════════╮\n");
	printf("\t\t║* * * * * * * * * * *  * * * * * * * * * * *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*     --------  蒲 尧  制 作  --------     *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*          欢迎使用该成绩管理系统          *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*                WELCOME！！！             *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*               请按回车键继续             *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*                  ----                    *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║* * * * * * * * * * *  * * * * * * * * * * *║\n");
	printf("\t\t╰════════════════════════════════════════════╯\n");
	printf("\n\n\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\n\n\n");
	getchar();
}


//菜单界面
void meun() {
	system("cls"); //屏幕清空
	printf("\n\n\n\n\n");
	printf("\t\t╭══════════════┤学生成绩管理系统├════════════╮\n");
	printf("\t\t║* * * * * * * * * * *  * * * * * * * * * * *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*     --------  蒲 尧  制 作  --------     *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*     --------    主 菜 单    --------     *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*             1. 录入学生数据              *║\n");
	printf("\t\t║*             2. 显示学生数据              *║\n");
	printf("\t\t║*             3. 修改学生数据              *║\n");
	printf("\t\t║*             4. 删除学生数据              *║\n");
	printf("\t\t║*             5. 查询成绩数据              *║\n");
	printf("\t\t║*             6. 降序输出数据              *║\n");
	printf("\t\t║*             7. 退出管理系统              *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║* * * * * * * * * * *  * * * * * * * * * * *║\n");
	printf("\t\t╰═══════════════════════════════════════════╯\n");
	printf("\t\t \1\t注:若姓名为两字请在姓名后添**以便于对齐\n");
	printf("\t\t \2\t请选择菜单选项(1-7):");
}


//从文件中读取学生的信息
void read_from_file() {
	FILE *fp;
	int i = 0;
	fp = fopen("data.db", "rb");
	if (!fp) {
		printf("打开文件data.db失败!\n");
		return;
	}
	fread(&num, 1, sizeof(num), fp); //先读取学生的个数
	for (i = 0;i<num;i++)
		fread(&s[i], 1, sizeof(student), fp); //读取每个学生的信息存放到结构体
	fclose(fp);//关闭文件
	printf("读取学生信息完毕!");
}


//向文件中写入学生的信息
void write_to_file() {
	FILE *fp;
	int i = 0;
	fp = fopen("data.db","wb+");
	if (!fp) {
		printf("打开文件data.db失败!\n");
		return;
	}
	fwrite(&num, 1, sizeof(num), fp); //先写入学生的个数
	for (i = 0;i<num;i++) fwrite(&s[i], 1, sizeof(student), fp); //写入每个学生的信息
	fclose(fp);//关闭文件
	printf("写入学生信息完毕!\n");
}


//添加学生信息
void Add() {
	int i = num;
	printf("请输入姓名:"); scanf("%s", s[i].name);
	printf("请输入学号:"); scanf("%s", s[i].no);
	printf("请输入高数成绩:"); scanf("%f", &s[i].math);
	printf("请输入英语成绩:"); scanf("%f", &s[i].English);
	printf("请输入物理成绩:"); scanf("%f", &s[i].physics);
	printf("请输入C语言成绩:"); scanf("%f", &s[i].C_language);
	s[i].S_all = s[i].math + s[i].English + s[i].physics + s[i].C_language; //计算出总分数
	s[i].Average = s[i].S_all / 4; //计算出平均分
	num++;
}


//显示学生信息
void Show() {
	int i = 0;
	printf("%s%13s%15s%15s%15s%15s%15s%15s\n", "姓名", "学号", "高数", "英语", "物理", "C语", "总分", "均分");
	for (i = 0;i<num;i++) printf("%s%11s%15.2f%15.2f%15.2f%15.2f%15.2f%15.2f\n", s[i].name, s[i].no, s[i].math, s[i].English, s[i].physics, s[i].C_language, s[i].S_all, s[i].Average);
}


//修改学生信息
void Change_information() {
	int choice = 1;
	printf("请输入你想按照什么修改\n1.学号；2.姓名\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:Change_information1();system("pause");break;
	case 2:Change_information2();system("pause");break;
	default:printf("没有该选项！");break;
	}
}


//修改学生信息
void Change_information1() {
	int i = 0;
	char no[CH]; //学号
	printf("请输入你要修改的学生学号:");
	scanf("%s", no);
	for (i = 0;i<num;i++)//先找到该学号对应的序号
		if (strcmp(s[i].no, no) == 0) {
			printf("请输入姓名:"); scanf("%s", s[i].name);
			printf("请输入学号:"); scanf("%s", s[i].no);
			printf("请输入高数成绩:"); scanf("%f", &s[i].math);
			printf("请输入英语成绩:"); scanf("%f", &s[i].English);
			printf("请输入物理成绩:"); scanf("%f", &s[i].physics);
			printf("请输入C语言成绩:"); scanf("%f", &s[i].C_language);
			s[i].S_all = s[i].math + s[i].English + s[i].physics + s[i].C_language; //计算出总分数
			s[i].Average = s[i].S_all / 4; //计算出平均分
			printf("%s%s", no, "学号同学的数据已改变!\n");
			return;
		}
	printf("%s%s", no, "学号同学没有数据!\n");
}



//按姓名修改学生信息
void Change_information2() {
	int i = 0;
	char name[CH];//姓名
	printf("请输入你要修改的学生姓名:");
	scanf("%s", name);
	for (i = 0;i<num;i++)//先找到该姓名对应的序号
		if (strcmp(s[i].name, name) == 0) {
			printf("请输入姓名:"); scanf("%s", s[i].name);
			printf("请输入学号:"); scanf("%s", s[i].no);
			printf("请输入高数成绩:"); scanf("%f", &s[i].math);
			printf("请输入英语成绩:"); scanf("%f", &s[i].English);
			printf("请输入物理成绩:"); scanf("%f", &s[i].physics);
			printf("请输入C语言成绩:"); scanf("%f", &s[i].C_language);
			s[i].S_all = s[i].math + s[i].English + s[i].physics + s[i].C_language; //计算出总分数
			s[i].Average = s[i].S_all / 4; //计算出平均分
			printf("%s%s", name, "姓名同学的数据已改变!\n");
			return;
		}
	printf("%s%s", name, "姓名同学没有数据!\n");
}



//删除学生信息
void Delete() {
	int choice = 1;
	printf("请输入你想按照什么删除\n1.学号；2.姓名\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:Delete1();system("pause");break;
	case 2:Delete2();system("pause");break;
	default:printf("没有该选项！");break;
	}
}


//按学号删除学生信息
void Delete1() {
	int i = 0, j = 0;
	char no[CH]; //学号
	printf("请输入你要删除的学生学号:");
	scanf("%s", no);
	for (i = 0;i<num;i++)//先找到该学号对应的序号
		if (strcmp(s[i].no, no) == 0 ) {
			for (j = i;j<num - 1;j++) s[j] = s[j + 1];
			num--; //数量减少 1
			printf("%s%s", no, "学号同学的数据已删除!\n");
			return;
		}
	printf("%s%s",no,"学号同学没有数据!\n");
}



//按姓名删除学生信息
void Delete2() {
	int i = 0, j = 0;
	char name[CH];//姓名
	printf("请输入你要删除的学生姓名:");
	scanf("%s", name);
	for (i = 0;i<num;i++)//先找到该姓名对应的序号
		if (strcmp(s[i].name, name) == 0) {
			for (j = i;j<num - 1;j++) s[j] = s[j + 1];
			num--; //数量减少 1
			printf("%s%s", name, "姓名同学的数据已删除!\n");
			return;
		}
	printf("%s%s", name, "姓名同学没有数据!\n");
}



//查找数据
void Search() {
	int choice = 1;
	printf("请输入你想按照什么查找\n1.学号；2.姓名\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:Search1();system("pause");break;
	case 2:Search2();system("pause");break;
	default:printf("没有该选项！");break;
	}
}


//按学号查询学生成绩
void Search1() {
	int i = 0;
	char no[CH]; //学号
	printf("请输入你要查询的学生学号:");
	scanf("%s", no);
	for (i = 0;i<num;i++)//先找到该学号对应的序号
		if (strcmp(s[i].no, no) == 0) {
			printf("%s\t%8s\t%8s\t%8s\t%6s\t%14s\t%12s\t%12s\n", "姓名", "学号", "高数", "英语", "物理", "C语言", "总分", "均分");
			printf("%s%11s%15.2f%15.2f%15.2f%15.2f%15.2f%15.2f\n", s[i].name, s[i].no, s[i].math, s[i].English, s[i].physics, s[i].C_language, s[i].S_all, s[i].Average);
			return;
		}
	printf("%s%s", no, "学号同学没有数据!\n");
}

//按姓名查询学生成绩
void Search2() {
	int i = 0;
	char name[CH];//姓名
	printf("请输入你要查询的学生姓名:");
	scanf("%s", name);
	for (i = 0;i<num;i++)//先找到该姓名对应的序号
		if (strcmp(s[i].name, name) == 0) {
			printf("%s\t%8s\t%8s\t%8s\t%6s\t%14s\t%12s\t%12s\n", "姓名", "学号", "高数", "英语", "物理", "C语言", "总分", "均分");
			printf("%s%11s%15.2f%15.2f%15.2f%15.2f%15.2f%15.2f\n", s[i].name, s[i].no, s[i].math, s[i].English, s[i].physics, s[i].C_language, s[i].S_all, s[i].Average);
			return;
		}
	printf("%s%s",name,"姓名同学没有数据!\n");
}


//成绩排序输出
void Sort() {
	int choice = 5;
	printf("请输入你想按照什么排名\n1.高数；2.英语；3.物理；4.C语言；5.平均分\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:Sort1();system("pause");break;
	case 2:Sort2();system("pause");break;
	case 3:Sort3();system("pause");break;
	case 4:Sort4();system("pause");break;
	case 5:Sort5();system("pause");break;
	default:printf("没有该选项！");break;
	}
}


//用高数成绩降序排序
void Sort1() {
	int i = 0, j = 0;
	student t;//用于排序交换的临时变量
	student s1[N]; //学生数组,用来排序的临时数组
	for (i = 0;i<num;i++)
		s1[i] = s[i];
	for (i = 0;i<num;i++)
		for (j = i + 1;j<num;j++)
			if (s1[i].math<s1[j].math) {
				t = s1[i];
				s1[i] = s1[j];
				s1[j] = t;
			}
	printf("%s\t%8s\t%8s\t%8s\t%6s\t%14s\t%12s\t%12s\n", "姓名", "学号", "高数", "英语", "物理", "C语言", "总分", "均分");
	for (i = 0;i<num;i++) printf("%s%10s%15.2f%15.2f%15.2f%15.2f%15.2f%15.2f\n", s1[i].name, s1[i].no, s1[i].math, s1[i].English, s1[i].physics, s1[i].C_language, s1[i].S_all, s1[i].Average);
}


//用英语成绩降序排序
void Sort2() {
	int i = 0, j = 0;
	student t;//用于排序交换的临时变量
	student s1[N]; //学生数组,用来排序的临时数组
	for (i = 0;i<num;i++)
		s1[i] = s[i];
	for (i = 0;i<num;i++)
		for (j = i + 1;j<num;j++)
			if (s1[i].English<s1[j].English) {
				t = s1[i];
				s1[i] = s1[j];
				s1[j] = t;
			}
	printf("%s\t%8s\t%8s\t%8s\t%6s\t%14s\t%12s\t%12s\n", "姓名", "学号", "高数", "英语", "物理", "C语言", "总分", "均分");
	for (i = 0;i<num;i++) printf("%s%10s%15.2f%15.2f%15.2f%15.2f%15.2f%15.2f\n", s1[i].name, s1[i].no, s1[i].math, s1[i].English, s1[i].physics, s1[i].C_language, s1[i].S_all, s1[i].Average);
}


//用物理成绩降序排序
void Sort3() {
	int i = 0, j = 0;
	student t;//用于排序交换的临时变量
	student s1[N]; //学生数组,用来排序的临时数组
	for (i = 0;i<num;i++)
		s1[i] = s[i];
	for (i = 0;i<num;i++)
		for (j = i + 1;j<num;j++)
			if (s1[i].physics<s1[j].physics) {
				t = s1[i];
				s1[i] = s1[j];
				s1[j] = t;
			}
	printf("%s\t%8s\t%8s\t%8s\t%6s\t%14s\t%12s\t%12s\n", "姓名", "学号", "高数", "英语", "物理", "C语言", "总分", "均分");
	for (i = 0;i<num;i++) printf("%s%10s%15.2f%15.2f%15.2f%15.2f%15.2f%15.2f\n", s1[i].name, s1[i].no, s1[i].math, s1[i].English, s1[i].physics, s1[i].C_language, s1[i].S_all, s1[i].Average);
}


//用C语言成绩降序排序
void Sort4() {
	int i = 0, j = 0;
	student t;//用于排序交换的临时变量
	student s1[N]; //学生数组,用来排序的临时数组
	for (i = 0;i<num;i++)
		s1[i] = s[i];
	for (i = 0;i<num;i++)
		for (j = i + 1;j<num;j++)
			if (s1[i].C_language<s1[j].C_language) {
				t = s1[i];
				s1[i] = s1[j];
				s1[j] = t;
			}
	printf("%s\t%8s\t%8s\t%8s\t%6s\t%14s\t%12s\t%12s\n", "姓名", "学号", "高数", "英语", "物理", "C语言", "总分", "均分");
	for (i = 0;i<num;i++) printf("%s%10s%15.2f%15.2f%15.2f%15.2f%15.2f%15.2f\n", s1[i].name, s1[i].no, s1[i].math, s1[i].English, s1[i].physics, s1[i].C_language, s1[i].S_all, s1[i].Average);
}


//用平均值降序排序
void Sort5() {
	int i = 0, j = 0;
	student t;//用于排序交换的临时变量
	student s1[N]; //学生数组,用来排序的临时数组
	for (i = 0;i<num;i++)
		s1[i] = s[i];
	for (i = 0;i<num;i++)
		for (j = i + 1;j<num;j++)
			if (s1[i].Average<s1[j].Average) {
				t = s1[i];
				s1[i] = s1[j];
				s1[j] = t;
			}
	printf("%s\t%8s\t%8s\t%8s\t%6s\t%14s\t%12s\t%12s\n", "姓名", "学号", "高数", "英语", "物理", "C语言", "总分", "均分");
	for (i = 0;i<num;i++) printf("%s%10s%15.2f%15.2f%15.2f%15.2f%15.2f%15.2f\n", s1[i].name, s1[i].no, s1[i].math, s1[i].English, s1[i].physics, s1[i].C_language, s1[i].S_all, s1[i].Average);
}


//退出查询
void Secede() {
	system("cls"); //屏幕清空
	printf("\n\n");
	printf("\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\n\n\n");
	printf("\t\t╭═════════════┤学生成绩管理系统├═════════════╮\n");
	printf("\t\t║* * * * * * * * * * *  * * * * * * * * * * *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*     --------  蒲 尧  制 作  --------     *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*        欢迎再次使用该成绩管理系统        *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*            WELCOME  TO  BACK！           *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*                再见啦！！！              *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*                （^_^）/~~                *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║*                                          *║\n");
	printf("\t\t║* * * * * * * * * * *  * * * * * * * * * * *║\n");
	printf("\t\t╰═══════════════════════════════════════════╯\n");
	printf("\n\n\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\n\n\n");
}
