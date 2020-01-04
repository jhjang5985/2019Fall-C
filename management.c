#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int i,j;
int main_exit;
void menu();

struct date{
    int month;
	int day;
	int year;
};

struct {
    char name[60];
    int acc_no;
	int age;
    char address[60];
    char phone[20];
    struct date dob;

}add,upd,check,rem;

void close(void)
{
    printf("\n\n\n\n자신의 팀 정보 작성");
}

void fordelay(int j)
{
    int i,k;
    for(i=0;i<j;i++)
        k=i;
}

void new_acc()
{
    int choice;
    FILE *ptr;

    ptr=fopen("record.dat","a+");
    account_no:
    system("cls");
    printf("\t\t\t record에 기록 추가 ");
    printf("\n계정 번호 입력:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.phone)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {
				printf("기존에 존재하는 계정 번호 입니다! 다른 번호를 입력해주세요");
                goto account_no;
            }
    }
    add.acc_no=check.acc_no;
    printf("\n이름:");
    scanf("%s",add.name);
    printf("\n생일(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\n나이:");
    scanf("%d",&add.age);
    printf("\n주소:");
    scanf("%s",add.address);
    printf("\n전화번호: ");
    scanf("%s",add.phone);

    
	fprintf(ptr,"%d %s %d/%d/%d %d %s %s\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.phone);
    fclose(ptr);
    printf("\n계정이 성공적으로 생성되었습니다.");
    
	while(1){
		printf("\n\n메인 메뉴로 가려면 1, 종료하려면 0을 눌러주세요:");
    	scanf("%d",&main_exit);
    	system("cls");
    	if((main_exit == 1) || (main_exit == 0))
    		break;
    	printf("\n0과 1중 하나를 입력해주세요!\a");
	}
    if (main_exit==1)
        menu();
    else if(main_exit==0)
        close();
}

void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\t이름\t\t\t주소\t\t\t전화번호\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.phone)!=EOF)
	{
       printf("\n%6d\t %10s\t\t\t%10s\t\t%s",add.acc_no,add.name,add.address,add.phone);
       test++;
	}
    fclose(view);
    
    if (test==0)
    {
		system("cls");
        printf("\n기록된 내용이 없습니다!\n");
	}

	while(1)
	{
		printf("\n\n메인 메뉴로 가려면 1, 종료하려면 0을 눌러주세요:");
    	scanf("%d",&main_exit);
    	system("cls");
    	if((main_exit == 1) || (main_exit == 0))
    		break;
    	printf("\n0과 1중 하나를 입력해주세요!\a");
	}
    if (main_exit==1)
        menu();
    else if(main_exit==0)
        close();
}

void edit(void)
{
	// 추가한 내용입니다.
	return;
}

void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("지울 고객의 계정 번호를 입력하세요:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.phone)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.phone);

        else
        {
			test++;
            printf("\n성공적으로 삭제되었습니다!\n");
        }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
	{
        printf("\n입력하신 계정 번호의 고객이 발견되지 않았습니다!!\a\a\a");
        erase_invalid:
        printf("\n다시 시도하려면 0, 메인 메뉴로 가려면 1, 종료하려면 다른 키를 눌러주세요:");
        scanf("%d",&main_exit);
        if(main_exit==0)
            erase();
        else if (main_exit==1)
            menu();
        else
            close();
    }
    else
    {
		printf("\n메인 메뉴로 가려면 1, 종료하려면 다른 키를 눌러주세요:");
	    scanf("%d",&main_exit);
	    system("cls");
	    if (main_exit==1)
	        menu();
	    else
	        close();
    }

}

void menu(void)
{
    int choice;
    system("cls");
    printf("\n\n\t\t\t 관리 시스템\n");
    printf("\n\n\t\t1. 계정 생성하기\n");
	printf("\t\t2. 기존 계정 삭제하기\n");
	printf("\t\t3. 전체 계정 정보보기\n");

	//직접 구현해보기 
	printf("\t\t4. 계정 정보 업데이트하기\n");

	//추가로 자신만의 기능 2개 이상 기능 구현하기 
	printf("\t\t5. 내가 구현한 기능\n");
	printf("\t\t6. 내가 구현한 기능\n");
	printf("\t\t7.종료\n\n\n\n\n");
	printf("\t\t 선택:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:
			new_acc();
	        break;
        case 2:
			erase();
        	break;
        case 3:
			view_list();
        	break;
	    case 4:
			edit();
	        break;
        case 5:
        	//추가할 함수 
        	break;
        case 6:
        	//추가할 함수 
        	break;
        case 7:
			close();
        	break;

    }



}
int main()
{
    char pass[10],password[10]="codewithc";
    int i=0;
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
    {
		printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
        system("cls");
        menu();
    }
    else
    {
	    printf("\n\nWrong password!!\a\a\a");
        login_try:
        printf("\nEnter 1 to try again and 0 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
        {
            system("cls");
            main();
        }

        else if (main_exit==0)
        {
            system("cls");
            close();
		}
        else
        {
			printf("\nInvalid!");
	        fordelay(1000000000);
	        system("cls");
	        goto login_try;
		}

    }
    return 0;
}

