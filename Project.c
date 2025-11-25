#include<stdio.h>
#include<string.h>
#define MAX 1000

struct Employee{
	char empId[20];
	char name[50];
	char position[15];
	double baseSalary;
	int workDay;
};

struct TimeSheet{
	char logId[20];
	char empId[20];
	char date[20];
	char status[10];
};

int addEmployee (struct Employee list[], int n);
int updateEmployee (struct Employee list[], int n);
int deleteEmployee (struct Employee list[], int n);
void displayEmployee (struct Employee list[], int n);

int main(){
	struct Employee list[MAX];
	int n = 0; 
	int choice;
	
	do{
		printf("\n|=============================================|\n");
	    printf("|        QUAN LY NHAN VIEN VA CHAM CONG       |");
	    printf("\n|=============================================|\n");
	    printf("|  1.Them nhan vien moi                       |\n");
	    printf("|  2.Cap nhat ho so nhan vien                 |\n");                 
	    printf("|  3.Xoa ho so nhan vien                      |\n");
	    printf("|  4.Hien thi danh sach nhan vien             |\n");
	    printf("|  5.Tim kiem nhan vien                       |\n");
	    printf("|  6.Sap xep nhan vien                        |\n");
	    printf("|  7.Cham cong ngay nhan vien                 |\n");
	    printf("|  8.Xem bang cong nhan vien                  |\n");
	    printf("|  9.Thoat                                    |\n");
	    printf("|=============================================|\n");
		
		printf("Moi ban nhap lua chon: ");
		scanf("%d",&choice);
		getchar(); 
		
		switch(choice){
			case 1:
				n = addEmployee(list,n);
				break;
			case 2:
				n = updateEmployee(list,n);
				break;
			case 3:
				n = deleteEmployee(list, n);
				break;
			case 4:
				displayEmployee(list,n);
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			default:
				printf("Khong hop le!");
		}
	}while(choice != 9);
	
	
	return 0;
}
int addEmployee(struct Employee list[], int n){
    char id[20];
    
    if(n >= MAX){
    	printf("Danh sach day!");
    	return n;
	}

    // nhap ma nhan vien 
    while (1) {
        printf("Nhap ma nhan vien: ");
        fgets(id,20,stdin);
        id[strcspn(id,"\n")] = '\0';

        if (strlen(id) == 0) {
            printf("Ma nhan vien khong duoc trong!\n");
            continue;
        }

        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp(list[i].empId, id) == 0) {
                flag = 1;   // 1 = ton tai
                break;
            }
        }
        if (flag == 1) {
            printf("Ma nhan vien da ton tai! Nhap lai.\n");
            continue;
        }

        break; 
    }

    strcpy(list[n].empId, id);

    // kiem tra nhap ten
    while (1) {
        printf("Ten nhan vien: ");
        fgets(list[n].name, 50, stdin);
        list[n].name[strcspn(list[n].name,"\n")] = '\0';

        if (strlen(list[n].name) == 0) {
            printf("Ten nhan vien khong duoc de trong!\n");
            continue;
        }
        break;
    }

    // kiem tra nhap chuc vu
    while (1) {
        printf("Chuc vu nhan vien: ");
        fgets(list[n].position, 15, stdin);
        list[n].position[strcspn(list[n].position,"\n")] = '\0';

        if (strlen(list[n].position) == 0) {
            printf("Chuc vu khong duoc de trong!\n");
            continue;
        }
        break;
    }

    // ktra nhap luong 
    while (1) {
        printf("Luong co ban: ");
        if (scanf("%lf", &list[n].baseSalary) != 1) {
            printf("Nhap sai dinh dang!\n");
            while (getchar() != '\n'); // Xoa toan bo buffer
            continue;
        }
        if (list[n].baseSalary <= 0) {
            printf("Luong khong hop le! Nhap lai.\n");
            continue;
        }
        break;
    }

    // cho phep nhap ngay cong
    while (1) {
    	int choose;
        printf("Nhap ngay cong (1. workday = 0, 2.Nhap tay): ");
        scanf("%d",&choose);
        getchar();
        
        if(choose == 1){
        	list[n].workDay = 0 ;
        	printf("Workday = 0 \n");
        	break;
		}else if(choose == 2){
			printf("Nhap ngay cong: ");
			scanf("%d",&list[n].workDay);
			getchar();
			
			if(list[n].workDay < 0 || list[n].workDay > 31){
				printf("Ngay cong phai tu 0 den 31\n");
				continue;
			}
			break;
		}else{
			printf("Khong hop le!\n");
		}
		
    }

    n++;

    printf("Them nhan vien thanh cong!\n");
    
    return n;
}

int updateEmployee(struct Employee list[], int n){
	char id[20];
	int pos = -1; 
	 
	while(1){
		//nhap id muon cnhat
        printf("Nhap ID nhan vien can cap nhat: ");
        fgets(id, 20, stdin);
        id[strcspn(id, "\n")] = '\0';
    
        //kiem tra id trong
        if(strlen(id) == 0){
    	    printf("Khong duoc de trong ID! Nhap lai\n");
    	    continue;
	    }

        // ktra tim vi tri
        for (int i = 0; i < n; i++) {
            if (strcmp(list[i].empId, id) == 0) {
                pos = i;
                break;
            }
        }

        //ktra id ton tai
        if (pos == -1) {
           printf("Khong tim thay ID! Nhap lai\n");
           continue;
        }
        break; 
	}

    // ktra cap nhat chuc vu
    while (1) {
        printf("Nhap chuc vu moi: ");
        fgets(list[pos].position, 15, stdin);
        list[pos].position[strcspn(list[pos].position, "\n")] = '\0';

        if (strlen(list[pos].position) == 0) {
            printf("Chuc vu khong duoc trong!\n");
            continue;
        }
        break;
    }

    // ktra cap nhat luong
    while (1) {
        printf("Luong co ban moi: ");
        if (scanf("%lf", &list[pos].baseSalary) != 1) {
            printf("Nhap sai dinh dang!\n");
            while (getchar() != '\n'); // Xoa toan bo buffer
            continue;
        }
        
        if (list[pos].baseSalary <= 0) {
            printf("Luong khong hop le! Nhap lai.\n");
            continue;
        }
        break;
    }
    
    printf("Cap nhat ho so nhan vien thanh cong!\n");
    
    return n;
}

int deleteEmployee (struct Employee list[], int n){
	char id[20];
	int pos = -1;
	
	while(1){
		printf("Nhap ma nhan vien muon xoa: ");
		fgets(id,20,stdin);    //nhap id
		id[strcspn(id,"\n")] = '\0';
		
		if(strlen(id) == 0){
			printf("Ma nhan vien khong duoc de trong! Nhap lai\n");   //ktra id rong
			continue;
		}
		
		for(int i = 0;i<n;i++){
			if(strcmp(list[i].empId,id) == 0){
				pos = i;
				break;
			}
		}
		
		if(pos == -1){
			printf("Khong tim thay nhan vien co ma %s! Nhap lai\n",id);     //ktra id ton tai, ko co kthuc luon
			continue;
		}
		
		break;
	}
	
	// XOA 
	for(int i = pos;i< n-1;i++){
		list[i] = list[i+1];
	}
	n--;
	printf("Xoa nhan vien %s thanh cong!\n",id);
	
	return n;
}

void displayEmployee(struct Employee list[], int n) {
    if (n == 0) {
        printf("Danh sach nhan vien hien dang trong!\n");
        return;
    }

    printf("\n====================== DANH SACH NHAN VIEN ======================\n");
    printf("%-10s | %-20s | %-12s | %-10s | %-5s\n",
           "Ma NV", "Ten NV", "Chuc vu", "Luong", "Cong");
    printf("-------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-10s | %-20s | %-12s | %-10.0lf | %-5d\n",
               list[i].empId,
               list[i].name,
               list[i].position,
               list[i].baseSalary,
               list[i].workDay);
    }

    printf("Hien thi danh sach thanh cong!\n");
}


