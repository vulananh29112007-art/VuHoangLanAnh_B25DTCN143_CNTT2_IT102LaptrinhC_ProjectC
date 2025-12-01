#include<stdio.h>       //printf, scanf, fgets, getchar
#include<string.h>      //strlen, strcmp, strcpy, strcspn, strncpy, strcat
#include<stdlib.h>      //system("cls")
#include<ctype.h>       //strcasecmp()
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
void sortEmployee();        

int main(){
	int choice;
	char buffer[100];
	
	do{
		system("cls"); 
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
		
		while(1){
			printf("Moi ban nhap lua chon: ");
			fgets(buffer,100,stdin);
			buffer[strcspn(buffer,"\n")] = '\0';
			
			if(strlen(buffer) == 0){  //kiem tra enter
				printf("Khong duoc de trong!\n");
				continue;
			}
			
			if(buffer[0] < '1' || buffer[0] > '9'){  //kiem tra ngoai khoang
				printf("Lua chon khong hop le!\n");
				continue;
			}
			
			if(strlen(buffer) > 1){  //kiem tra so luong nhap
				printf("Chi duoc nhap 1 so!\n");
				continue;
			}
			
			choice = buffer[0] - '0';    //chuyen char thanh int
			
			break;
		}
		 
		
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

    int perPage = 2;
    int totalPage = (n + perPage - 1) / perPage;
    int page = 1;

    char choice[10];

    while (1) {
        // tinh vi tri
        int start = (page - 1) * perPage;
        int end = start + perPage;
        if (end > n){
        	end = n;
		}

        // IN TRANG
        printf("\n=== TRANG %d / %d ===\n", page, totalPage);

        printf("+----+------------+----------------------+---------------+------------+----------+\n");
        printf("| STT| Ma NV      | Ten NV               | Chuc vu       | Luong      | Ngay cong|\n");
        printf("+----+------------+----------------------+---------------+------------+----------+\n");

        for (int i = start; i < end; i++) {
            printf("| %2d | %-10s | %-20s | %-10s    | %10.2lf | %8d |\n",
                   i + 1,
                   list[i].empId,
                   list[i].name,
                   list[i].position,
                   list[i].baseSalary,
                   list[i].workDay);
        }
        printf("+----+------------+----------------------+---------------+------------+----------+\n");

        // MENU DIEU HUONG
        printf("\nLua chon:\n");
        printf(" N - Trang tiep theo\n");
        printf(" P - Trang truoc\n");
        printf(" G - Nhay den trang bat ky\n");
        printf(" E - Thoat\n");
        printf("Nhap lua chon: ");

        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\n")] = 0;

        // XU LI LUA CHON
        if (strcasecmp(choice, "N") == 0) {
            if (page < totalPage) page++;
            else printf("Ban dang o trang cuoi!\n");

        } else if (strcasecmp(choice, "P") == 0) {
            if (page > 1) page--;
            else printf("Ban dang o trang dau!\n");

        } else if (strcasecmp(choice, "G") == 0) {
            int gotoPage;
            printf("Nhap so trang muon den (1-%d): ", totalPage);

            if (scanf("%d", &gotoPage) != 1) {
                printf("Dinh dang khong hop le!\n");
                while (getchar() != '\n');
                continue;
            }

            while (getchar() != '\n'); // clear buffer

            if (gotoPage >= 1 && gotoPage <= totalPage) {
                page = gotoPage;
            } else {
                printf("Trang khong ton tai!\n");
            }

        } else if (strcasecmp(choice, "E") == 0) {
            printf("Thoat khoi hien thi danh sach.\n");
            return;

        } else {
            printf("Lua chon khong hop le!\n");
        }
    }
}

void toLowerstr(char s[]){
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] += 32;
        }
    }
}


// F05 
void searchEmployee(){
    char name[50];
    char lowerInput[50];
    char lowerEmpname[50];
    if(n == 0){
        printf("Danh sach nhan vien hien dang trong!\n");
        return;
    }
    printf("Nhap ten nhan vien muon tim kiem: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';
    if(strlen(name) == 0){
        printf("Ten tim kiem khong duoc de trong!\n");
        return;
    }
    strcpy(lowerInput, name);
    toLowerstr(lowerInput);

    int stt = 1;        // chi de danh stt 
    int found = 0;      // dem so nv thuc su tim dc 

    printf("\n+----+------------+-------------------------+-----------------+---------------+-----------+\n");
    printf("| STT| Ma NV     | Ho va ten               | Chuc vu         | Luong co ban  | Ngay cong |\n");
    printf("+----+------------+-------------------------+-----------------+---------------+-----------+\n");

    for(int i = 0; i < n; i++){
        strcpy(lowerEmpname, list[i].name);
        toLowerstr(lowerEmpname);
        if(strstr(lowerEmpname, lowerInput) != NULL){
            char displayName[24] = {0};
            strncpy(displayName, list[i].name, 23);
            displayName[23] = '\0';
            if (strlen(list[i].name) > 23) strcat(displayName, "...");

            printf("| %2d | %-10s | %-23s | %-15s | %13.0lf | %9d |\n",
                   stt++,
                   list[i].empId,
                   displayName,
                   list[i].position,
                   list[i].baseSalary,
                   list[i].workDay);
            found++;    // tang moi khi tim thay 1 nv 
        }
    }

    printf("+----+------------+-------------------------+-----------------+---------------+-----------+\n");

    if(found == 0){
        printf("=> Khong tim thay nhan vien nao phu hop!\n");
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

