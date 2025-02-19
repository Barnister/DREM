#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define N 100

struct students
{
	char name[N],sex[N];
	int age;
    long long int id;
};

struct class_t
{
	struct students s[N];
	int n;
};

void mnue()
{
	
	printf("STUDENT MANAGE SYSTEM\n");
	printf("#######################################################\n");
	printf("|1、添加新学生的全部信息|\n");
	printf("|2、删除已有学生的信息	|\n");
	printf("|3、更改学生的信息		|\n");
	printf("|4、查找学生信息|\n");
	printf("|5、显示全部学生信息	|\n");
	printf("|6、退出系统			|\n");
}
	

void add_student(struct class_t* cl);
void re_student(struct class_t* cl);
void pop_student(struct class_t* cl);
void show_student(struct class_t* cl);
int fin_student(struct class_t* cl);

	


int main()
{
	struct students S[N];
	struct class_t Cl;
	    int c_math;
	Cl.n = 0;
	mnue();
    while(1)
    {
        re_run:
            printf("输入选项:\n");
            scanf("%d",&c_math);
        switch (c_math)
        {
            case 1:
                add_student(&Cl);
                break;
            case 2:
                pop_student(&Cl);
                break;
            case 3:
                re_student(&Cl);
                break;
            case 4:
                fin_student(&Cl);
                break;
            case 5:
                show_student(&Cl);
                break;
            case 6:
                return 0;
            default:
                printf("输入错误请重新输入：\n");
                goto re_run;
        }
    }
	return 0;
}

void add_student(struct class_t* cl)
{
    printf("请输入添加学生姓名：\n");
    scanf("%s",cl->s[cl->n].name);
    printf("请输入学生年龄:\n");
    scanf("%d",&cl->s[cl->n].age);
    printf("输入学生的性别：\n");
    scanf("%s",cl->s[cl->n].sex);
    printf("请输入学生的学号：\n");
    scanf("%lld",&cl->s[cl->n].id);
    (cl->n)++;

}

void re_student(struct class_t* cl)
{
	int index = fin_student(cl);
	int title;
	printf("请输入想修改的内容：\n1、姓名 2、学号 3、性别 4、年龄\n");
	scanf("%d",&title);
	switch (title)
	{
		case 1:
			printf("修改姓名 请输入修改后的内容：\n");
			scanf("%s",cl->s[index].name);
			break;
		case 2:
			printf("修改学号 请输入修改后的内容：\n");
			scanf("%lld",&cl->s[index].id);
			break;
		case 3:
			printf("修改性别 请输入修改后的内容：\n");
			scanf("%s",cl->s[index].sex);
			break;
		case 4:
			printf("修改年龄 请输入修改后的内容：\n");
			scanf("%d",&cl->s[index].age);
			break;
		default:
			printf("错误：程序停止");
			break;
	}

}
int fin_student(struct class_t* cl)
{
		char n[N];
		int i,j,index,title;
        long long int id;
		int choos;
		printf("请选择查询方式并输入对应数字\n1、姓名查询\n2、学号查询\n：");
		scanf("%d",&choos);
		switch (choos)
		{
			case 1:
				printf("输入学生姓名：\n");
				scanf("%s",n);
				break;
			case 2:
				printf("请输入学生学号：\n");
				scanf("%lld",&id);
				break;
			default:
				printf("错误请重新输入：\n");
				fin_student(cl);
		}
		if(choos == 1)
		
			for(i=0;i<(cl->n);i++)
			{
				for(j=0;j<(cl->n);j++)
				{
					if(cl->s[i].name[j]==n[j])
						title=1;
					else
						title=0;
						break;
				}
				if(title=1)
					index=i;

			}
		if(choos==2)
			for(i =0;i<(cl->n);i++)
			{
				if(cl->s[i].id==id)
					index = i;
			}
		printf("finding this student's information is:\n|%s|\n|%s|\n|%lld|\n|%d|\n",cl->s[index].name,cl->s[index].sex,cl->s[index].id,cl->s[index].age);
	return index;
}

void show_student(struct class_t* cl)
{
	int i,j,index;
	for(i=0;i<(cl->n);i++)
	{
		printf("|%d#%s,%s,%lld,%d|\n",cl->n,cl->s[i].name,cl->s[i].sex,cl->s[i].id,cl->s[i].age);
	}
}

void pop_student(struct class_t* cl)
{
	int i,j,index = fin_student(cl);
	printf("确认是否删除该学生(1、是 2、否)\n：");
	scanf("%d",i);
	if(i==1){
		strcpy(cl->s[index].name,cl->s[index+1].name);
		strcpy(cl->s[index].sex,cl->s[index+1].sex);
		cl->s[index].age = cl->s[index+1].age;
		cl->s[index].id = cl->s[index+1].id;
		printf("删除完成\n");}
	else{
		printf("STOP");}
		




}



	


		















	

