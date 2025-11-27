#include<stdio.h>
#include<string.h>
#include <time.h>
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

struct TimeSheet timeSheet[MAX * 32];   
int sheetCount = 0;

void addEmployee ();
void updateEmployee ();
void deleteEmployee ();
void displayEmployee ();
void searchEmployee (); 
void sortEmployee();        
void attendEmployee();     
void viewTimeSheet();       
void getCurrentDate(char* date); 

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
				attendEmployee();
				break;
			case 8:
				viewTimeSheet();
				break;
			case 9:
				break;
			default:
				printf("Khong hop le!\n");
		}
	}while(choice != 9);
	
	
	return 0;
}

//F01
void addEmployee(){
    char id[20];
    
    if(n >= MAX){
    	printf("Danh sach day!\n");
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
	
	if (n == 0) {
        printf("Danh sach nhan vien hien dang trong!\n");
        return;
    }
	 
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
	
	if (n == 0) {
        printf("Danh sach nhan vien hien dang trong!\n");
        return;
    }
	
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
	while(1){
		int decide;
	    printf("Chac chan muon xoa/sa thai?\n");
	    printf("1. Co\n2.Khong\n");
	    scanf("%d",&decide);
	    getchar();
	
	    if(decide != 1 && decide != 2){
		    printf("Lua chon khong hop le!");
		    continue;
	    }
	    
	    //  XAC NHAN XOA?
	    if(decide == 1){
		    for(int i = pos;i< n-1;i++){
		        list[i] = list[i+1];
	        }
	        n--;
	        printf("Xoa nhan vien %s thanh cong!\n",id);
    	}else{
	    	printf("Huy xoa nhan vien %s thanh cong!\n",id);
	    }
	    break;
    }
	
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
        printf("\nNhap trang muon xem(1 - %d):  ", totalPage);
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
    if (end > n){
    	end = n;
	}

    printf("\n================ DANH SACH NHAN VIEN TRANG %d/%d ================\n",
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
		printf("Danh sach nhan vien hien dang trong!\n");  //ktra danh sach rong
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
		    printf("Ma nhan vien: %s\n",list[i].empId);
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

// F07 
void attendEmployee() {
    char empId[20];
    char currentDate[20];
    int pos = -1;

    if (n == 0) {
        printf("Danh sach nhan vien trong! Khong the cham cong.\n");
        return;
    }

    getCurrentDate(currentDate);

    // Nhap ma nhan vien
    while(1) {
        printf("Nhap ma nhan vien can cham cong: ");
        fgets(empId, 20, stdin);
        empId[strcspn(empId, "\n")] = '\0';

        if (strlen(empId) == 0) {
            printf("Ma nhan vien khong duoc de trong!\n");
            continue;
        }

        // Tim nhan vien
        for (int i = 0; i < n; i++) {
            if (strcmp(list[i].empId, empId) == 0) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            printf("Khong tim thay ma nhan vien nay! Nhap lai.\n");
            continue;
        }
        break;
    }

    // Kiem tra cham cong hom nay chua
    int daCham = 0;
    for (int i = 0; i < sheetCount; i++) {
        if (strcmp(timeSheet[i].empId, empId) == 0 &&
            strcmp(timeSheet[i].date, currentDate) == 0) {
            daCham = 1;
            break;
        }
    }

    if (daCham) {
        printf("Nhan vien %s da duoc cham cong vao ngay nay (%s)!\n", empId, currentDate);
        printf("Thong bao: Nhan vien da duoc cham cong vao ngay nay.\n");
        return;
    }

    // Tăng workday
    list[pos].workDay++;

    // T?o record TimeSheet
    sprintf(timeSheet[sheetCount].logId, "LOG%04d", sheetCount + 1);
    strcpy(timeSheet[sheetCount].empId, empId);
    strcpy(timeSheet[sheetCount].date, currentDate);
    strcpy(timeSheet[sheetCount].status, "Di lam");

    sheetCount++;

    printf("Cham cong thanh cong cho nhan vien %s!\n", list[pos].name);
    printf("Ngay: %s | Ngay cong hien tai: %d\n", currentDate, list[pos].workDay);
}

// F08 
void viewTimeSheet() {
    char empId[20];
    int pos = -1;
    char currentDate[20]; // khogn can thiet

    if (n == 0) {
        printf("Khong co nhan vien nao trong danh sach!\n");
        return;
    }

    // Nhpa mma nhan vien
    while(1) {
        printf("Nhap ma nhan vien can xem bang cong: ");
        fgets(empId, 20, stdin);
        empId[strcspn(empId, "\n")] = '\0';

        if (strlen(empId) == 0) {
            printf("Ma nhan vien khong duoc de trong!\n");
            continue;
        }

        for (int i = 0; i < n; i++) {
            if (strcmp(list[i].empId, empId) == 0) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            printf("Khong tim thay nhan vien! Nhap lai.\n");
            continue;
        }
        break;
    }

    // Hien thi thong tin nhan vien
    printf("\n================ THONG TIN NHAN VIEN ================\n");
    printf("Ma NV     : %s\n", list[pos].empId);
    printf("Ho ten    : %s\n", list[pos].name);
    printf("Chuc vu   : %s\n", list[pos].position);
    printf("Luong CB  : %.2lf\n", list[pos].baseSalary);
    printf("Ngay cong : %d\n", list[pos].workDay);
    printf("================================================\n");

    // In bang cham cong cua nhan vien nay
    printf("\n--- Lich su cham cong ---\n");
    printf("%-10s | %-12s | %s\n", "LogID", "Ngay", "Trang thai");
    printf("----------------------------------------\n");

    int found = 0;
    for (int i = 0; i < sheetCount; i++) {
        if (strcmp(timeSheet[i].empId, empId) == 0) {
            printf("%-10s | %-12s | %s\n",
                   timeSheet[i].logId,
                   timeSheet[i].date,
                   timeSheet[i].status);
            found = 1;
        }
    }

    if (!found) {
        printf("Chua co lich su cham cong.\n");
    }

    printf("Tong cong: %d ngay lam viec.\n", list[pos].workDay);
}

void getCurrentDate(char* date) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);  
    
    if (tm_info == NULL) {
        strcpy(date, "01/01/2000");  // fallback neu loi  
        return;
    }
    
    sprintf(date, "%02d/%02d/%04d", 
            tm_info->tm_mday, 
            tm_info->tm_mon + 1, 
            tm_info->tm_year + 1900);
}



