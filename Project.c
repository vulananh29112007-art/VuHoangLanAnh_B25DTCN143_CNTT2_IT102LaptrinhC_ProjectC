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

struct Employee list[MAX];
int n = 0; 

void addEmployee ();
void updateEmployee ();
void deleteEmployee ();
void displayEmployee ();
void searchEmployee (); 

int main(){
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
			addEmployee();
				break;
			case 2:
			updateEmployee();
				break;
			case 3:
			deleteEmployee();
				break;
			case 4:
			displayEmployee();
				break;
			case 5:
			searchEmployee();
				break;
			case 6:
			sortEmployee();
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

//F01
void addEmployee(){
    char id[20];
    
    if(n >= MAX){
    	printf("Danh sach day!");
    	return ;
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
}

//F02
void updateEmployee(){
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
}

//F03
void deleteEmployee (){
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
}

//F04
void displayEmployee() {
    if (n == 0) {
        printf("Danh sach nhan vien hien dang trong!\n");
        return;
    }

    int pageSize = 5;   // so nhan vien moi trang
    int totalPage = (n + pageSize - 1) / pageSize;  // lam tron len
    int page;

    while (1) {
        printf("\nNhap trang muon xem (1 ? %d): ", totalPage);
        scanf("%d", &page);
        getchar();

        if (page < 1 || page > totalPage) {
            printf("So trang khong hop le! Vui long nhap lai.\n");
            continue;
        }
        break;
    }

    int start = (page - 1) * pageSize;
    int end = start + pageSize;
    if (end > n) end = n;

    printf("\n=============== DANH SACH NHAN VIEN — TRANG %d/%d ===============\n",
           page, totalPage);
    printf("%-10s | %-20s | %-12s | %-10s | %-5s\n",
           "Ma NV", "Ten NV", "Chuc vu", "Luong", "Cong");
    printf("-------------------------------------------------------------------\n");

    for (int i = start; i < end; i++) {
        printf("%-10s | %-20s | %-12s | %-10.10f | %-5d\n",
               list[i].empId,
               list[i].name,
               list[i].position,
               list[i].baseSalary,
               list[i].workDay);
    }

    printf("Hien thi thanh cong!\n");
}

//F05
void searchEmployee(){
	char name[50];
	if(n == 0){
		printf("Danh sach hien dang trong!\n");  //ktra danh sach rong
		return;
	}
	
	printf("Nhap ten nhan vien muon tim kiem: ");
	fgets(name,50,stdin);
	name[strcspn(name,"\n")] = '\0';
	
	if (strlen(name) == 0) {
        printf("Ten tim kiem khong duoc de trong!\n"); //ktra trong 
        return;
    }

		
	int flag = 0;
	for(int i = 0;i<n;i++){
		if(strstr(list[i].name,name) != NULL){   //dung ham strstr de ktra chuoi con
			printf("Ten nhan vien: %s\n",list[i].name);
			printf("Chuc vu: %s\n", list[i].position);
			printf("Luong: %lf\n",list[i].baseSalary);
			printf("Ngay cong: %d\n",list[i].workDay);
			flag = 1;
		}
	}
		
	if(!flag){
		printf("Khong tim thay!\n");
		return;
	}

}

// F06
void sortEmployee(){
	if (n == 0) {
        printf("Danh sach nhan vien hien dang trong!\n");
        return;
    }
    
    int choose;
    while(1){
    	printf("1.Tang dan\n");
        printf("2.Giam dan\n");
        printf("Nhap lua chon: ");
        scanf("%d",&choose);
        getchar();
        
        if(choose != 1 && choose != 2){
        	printf("Lua chon khong hop le!\n");
        	continue;
		}
    
        int swap = 0;
        struct Employee temp;
    
        for(int i = 0; i < n-1 ;i++){
        	for(int j = 0;j < n-1-i ;j++){
        		swap = 0;
    	    	if(choose == 1 && list[j].baseSalary > list[j+1].baseSalary){   //SX TANG DAN
    		    	swap = 1;
			    }
			    if(choose == 2 && list[j].baseSalary < list[j+1].baseSalary){   //SX GIAM DAN
				    swap = 1;
		    	}
    		    if(swap == 1){  //hoan doi
    		    	temp = list[j];
    		    	list[j] = list[j+1];
    			    list[j+1] = temp;
		    	}	
	    	}
    	}
	
    	if(choose == 1){
	    	printf("Sap xep danh sach tang dan theo luong thanh cong!\n");
	    }
		if (choose == 2){
	    	printf("Sap xep danh sach giam dan theo luong thanh cong!\n");
    	}
    	break;
	}
    	
	
}

