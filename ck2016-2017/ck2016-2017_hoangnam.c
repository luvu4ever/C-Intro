#include<stdio.h>
#include<string.h>
typedef struct {
    char Name[30],Description[500],Address[100];
    float Rating;
}  Restaurant;
int n=0;Restaurant a[20];

void printMenu(){
    printf("\t%5sMENU\n","");
    printf("1. Nhap thong tin cac nha hang\n");
    printf("2. In thong tin cac nha hang\n");
    printf("3. Tim kiem theo ten\n");
    printf("4. Tim kiem theo mo ta\n");
    printf("5. Sap xep\n");
    printf("6. Thoat\n");

}
void printRes(int i){
    printf("Nha hang %d\n",i+1);
    printf("Name: %s\n",a[i].Name);
    printf("Description: %s\n",a[i].Description);
    printf("Rating: %.1f\n",a[i].Rating);
    printf("Address: %s\n\n",a[i].Address);
}
int checkPrint(){
    int x;
    do{
        printf("Moi ban chon chuc nang (1->6): ");
        scanf("%d",&x);
        getchar();
    }while(x>6||x<1);
    return x;
}
int task1(int start){
    if(start>0) printf("Ban dang them nha hang!\n");
    int num;
    do{
        printf("Moi ban nhap so nha hang (>0): ");
        scanf("%d",&num);
        getchar();
        if(num<=0) printf("Yeu cau nhap lai\n");
    }while(num<=0);
    num+=start;
    for (int i=start;i<num;i++){
        printf("Nha hang %d\n",i+1);
        printf("Name: ");
        fgets(a[i].Name,30,stdin);
        a[i].Name[strcspn(a[i].Name,"\n")]='\0';
        printf("Description: ");
        fgets(a[i].Description,500,stdin);
        a[i].Description[strcspn(a[i].Description,"\n")]='\0';
        do{
            printf("Rating (0.0->5.0): ");
            scanf("%f",&a[i].Rating);
            getchar();
            if(a[i].Rating<0||a[i].Rating>5)
                printf("Nhap sai!\n");
        }while (a[i].Rating<0||a[i].Rating>5);
        printf("Address: ");
        fgets(a[i].Address,100,stdin);
        a[i].Address[strcspn(a[i].Address,"\n")]='\0';
        printf("\n");
    }
    printf("Nhap thanh cong!\n");
    return num;
}
void task2(){
    for (int i=0;i<n;i++)printRes(i);
}
void task3(){
    char name[30];
    printf("Ban dang tim theo ten!\n");
    printf("Nhap ten nha hang ban muon tim: ");
    fgets(name,30,stdin);
    name[strcspn(name,"\n")]=0;
    for (int i=0;i<n;i++)
        if(strcasecmp(a[i].Name,name)==0) printRes(i);
}
void task4(){
    char des[30];
    printf("Ban dang tim theo mo ta!\n");
    printf("Nhap ten nha hang ban muon tim: ");
    fgets(des,500,stdin);
    des[strcspn(des,"\n")]=0;
    for (int i=0;i<n;i++)
        if(strcasestr(a[i].Description,des)) printRes(i);
}
void task5(){
    Restaurant sorted[20],tg;int index[20],itg;
    for(int i=0;i<n;i++) {
        sorted[i]=a[i];
        index[i]=i;
    }
    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++)
            if(sorted[i].Rating<sorted[j].Rating){
                tg=sorted[i];           itg=index[i];
                sorted[i]=sorted[j];    index[i]=index[j];
                sorted[j]=tg;           index[j]=itg;
            }
    for (int i=0;i<n;i++) printRes(index[i]);
}
int main(){
  
    //#menu
    int task;
    while(1){
        printMenu();
        task=checkPrint();
        switch(task){
            case 1: n=task1(n);
            break;
            case 2: task2();
            break;
            case 3: task3();
            break;
            case 4: task4();
            break;
            case 5: task5();
            break;
            case 6: return 0;
            break;
        }
    }
  
    return 0;
}
