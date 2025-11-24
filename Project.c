#include<stdio.h>
#include<string.h>
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

void addEmployee(struct Employee list[], int *n){
	char id[20];
	
	//nhap ma nhan vien
	printf("Nhap ma nhan vien: ");
	fgets(id,20,stdin);
	id[strcspn(id,"\n")] = '\0';
	
	//kiem tra trong
	if(strlen(id) == 0){
		printf("Ma nhan vien khong duoc trong!\n");
		return;
	}
	
	//kiem tra trung lap
	for(int i = 0;i<*n;i++){
		if(strcmp(list[i].empId,id) == 0){
			printf("Ma nhan vien da ton tai!");
			return;
		}
	}
	
	//cho id vao struct 
	strcpy(list[*n].empId, id);
	
	//nhap cai con lai
	printf("Ten nhan vien: ");
	fgets(list[*n].name,50,stdin);
	list[*n].name[strcspn(list[*n].name,"\n")] = '\0';
	if(strlen(list[*n].name) == 0){
		printf("Ten nhan vien khong duoc de trong !");
		return;
	}
	
	printf("Chuc vu nhan vien: ");
	fgets(list[*n].position,15,stdin);
	list[*n].position[strcspn(list[*n].position,"\n")] = '\0';
	if(strlen(list[*n].position) == 0){
		printf("Chuc vu nhan vien khong duoc de trong!");
		return; 
	}
	
	printf("Luong co ban: ");
	scanf("%lf",&list[*n].baseSalary);
	getchar();
	if(list[*n].baseSalary <= 0 ){
		printf("Luong co ban khong hop le!");
		return; 
	}
	
	list[*n].workDay = 0;
	
	(*n)++;
	
	printf("Them nhan vien thanh cong!\n");
}

void updateEmployee(struct Employee list[], int *n){
	char id[20];
	int pos = -1; 
	 
	printf("Nhap ID nhan vien can cap nhat: ");
	fgets(id,20,stdin);
	id[strcspn(id,"\n")] = '\0';
	 
	//tim kiem id 
	for(int i = 0;i<*n;i++){
		if(strcmp(list[i].empId,id) == 0){
			pos = i;
			break;
		}
	}
	
	if(pos == -1){
		printf("Khong tim thay Id!");
		return;
	}
	
	//cap nhat
	printf("Nhap chuc vu nhan vien moi: ");
	fgets(list[pos].position,15,stdin);
	list[pos].position[strcspn(list[pos].position,"\n")] = '\0';
	if(strlen(list[pos].position) == 0){
		printf("Khong duoc de chuc vu trong!\n");
		return;
	}
	
	printf("Nhap luong co ban moi: ");
	scanf("%lf",&list[pos].baseSalary);
	getchar();
	if(list[pos].baseSalary <= 0){
		printf("Luong co ban khong hop le!\n");
		return;
	}
	
	printf("Cap nhat thanh cong!");
}

void displayEmployeeList(struct Employee list[], int n) {
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


int main(){
	struct Employee list[100] = {
		{"NV01", "Nguyen Van A", "Nhan vien", 5000000, 10},
		{"NV02", "Tran Thi B", "Quan ly", 7000000, 12},
		{"NV03", "Le Van C", "Ke toan", 6000000, 8}
	};
	int n = 3; 
	int choice;
	
	do{
		printf("\n===================MENU====================\n");
		printf("1.Them nhan vien moi.\n");
		printf("2.Cap nhat ho so.\n");
		printf("3.Sa thai/Nghi viec(xoa).\n");
		printf("4.Hien thi danh sach.\n");
		printf("5.Tra cuu(tim kiem).\n");
		printf("6.Sap xep danh sach.\n");
		printf("7.Cham ngay cong.\n");
		printf("8.Xem bang cong.\n");
		
		printf("Moi ban nhap lua chon: ");
		scanf("%d",&choice);
		getchar(); 
		
		switch(choice){
			case 1:
				addEmployee(list,&n);
				break;
			case 2:
				updateEmployee(list,&n);
				break;
			case 3:
				break;
			case 4:
				displayEmployeeList(list,n);
				break;
		}
	}while(choice>0 && choice<9);
	
	
	return 0;
}


