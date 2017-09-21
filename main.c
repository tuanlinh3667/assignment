#include<stdbool.h>
#include<stdio.h>
#include <ctype.h>
#include <memory.h>

void main() {
    createMenu();
}

createMenu() {
    while (true) {
        int choice;
        printf("-----------------Menu-----------------\n");
        printf("1. Show student list.\n");
        printf("2. Add new student.\n");
        printf("3. Edit student.\n");
        printf("4. Delete student.\n");
        printf("5. Exit.\n");
        printf("--------------------------------------\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar();
        if (choice == 5) {
            printf("End program.");
            break;
        }
        switch (choice) {
            case 1:
                // do something.
                printf("Show student list.\n");
                showStudent();
                break;
            case 2:
                // do something.
                addStudent();
                break;
            case 3:
                // do something.
                printf("Edit student.\n");
                editStudent();
                break;
            case 4:
                // do something.
                printf("Delete student.\n");
                deleteStudent();
                break;
            default:
                //
                printf("Please enter a number from 1 to 5.\n");
                break;
        }
    }
}

showStudent() {
    FILE *f1read = fopen("students.txt","r");
    f1read = fopen("students.txt","r");
    //r = read = đọc.
    if (f1read == NULL){
        printf("CAN'T READ FILE! FILE IS ERROR!!! \n");
        fclose(f1read);

    }else{
        char buffer[100];// tạo một array để đọc dữ liệu ra.
        while (fgets(buffer, 100, f1read)) { // đọc nội dung trong file cho đến khi hết dữ liệu.
            printf("%s", buffer);
        }
        fclose(f1read);
    }
}

addStudent() {
    // tạo ra các mảng:
    char name[100];
    char birthday[100];
    char phone[100];
    // dùng hàm bool là hầm chỉ trả về hai giá trị đúng hoặc sai:
    bool isValid = false; // Kiểm tra tính hợp lý của tên.
    printf("Add new student.\n");
    while (!isValid){ // Nếu tên không h?p l? th? ti?p t?c b?t nh?p.
        printf("Please enter name: \n");
        fgets(name, sizeof(name), stdin);
        int lengthOfName = strlen(name) - 1;
        if (lengthOfName < 3) {
            printf("Name is too short. Please enter number between 3 to 15 character.\n");
        } else if (lengthOfName > 15) {
            printf("Name is too long. Please enter number between 3 to 15 character.\n");
        } else {
            isValid = true;
        }
    }
    printf("Please enter birthday: \n");
    fgets(birthday, sizeof(birthday), stdin);

    printf("Please enter phone: \n");
    fgets(phone, sizeof(phone), stdin);
    printf("\tThe student information \n");
    printf("---------------------------- \n");
    printf("Name: %s \n", name);
    printf("Birthday: %s \n", birthday);
    printf("Phone: %s \n", phone);

    FILE *f1 = fopen("students.txt","w"); // mở file để ghi.
    //mở một file tên là names.txt ra để ghi.
    //w = ghi.
    fputs(name,f1);  // Ghi nội dung từ biến name ra file ‘names.txt
    fputs(birthday,f1);  // Ghi nội dung từ biến name ra file ‘names.txt
    fputs(phone,f1);  // Ghi nội dung từ biến name ra file ‘names.txt
    fclose(f1);
    printf("Done! The student information saved! \n");
}

editStudent() {
    char editname[100];
    char editbirthday[100];
    char editphone[100];

    printf("Please enter edit students' name: \n");
    fgets(editname, sizeof(editname), stdin);

    printf("Please enter edit students'birthday: \n");
    fgets(editbirthday, sizeof(editbirthday), stdin);

    printf("Please enter edit students'phone: \n");
    fgets(editphone, sizeof(editphone), stdin);

    printf("\tThe student information after edit \n");
    printf("---------------------------- \n");
    printf("Edit Name: %s \n", editname);
    printf("Edit Birthday: %s \n", editbirthday);
    printf("Edit Phone: %s \n", editphone);

    FILE *f1edit = fopen("students.txt","w"); // mở file để ghi.
    //mở một file tên là names.txt ra để ghi.
    //w = ghi.
    fputs(editname,f1edit);  // Ghi nội dung từ biến name ra file ‘names.txt
    fputs(editbirthday,f1edit);  // i nội dung từ biến name ra file ‘names.txt
    fputs(editphone,f1edit);  // Ghi nội dung từ biến name ra file ‘names.txt
    fclose(f1edit);
    printf("Edit Done! \n");
}

deleteStudent() {
    FILE *f1del;                                                        // tạo con trỏ
    f1del = fopen("students.txt", "w");                                 // Mở file với quyền ghi
    fprintf(f1del, "%s", "The students' information deleted !!! \n");   //truyền dữ liệu vào luồng stream
    fclose(f1del);                                                      //đóng file
    int del = remove("students.txt");                                   // Tạo một biến kiểu integer là kết quả trả về khi thực hiện hàm remove thực hiện thành công
    if(del == 0){                                                       // nếu biến dell = 0 tức là hàm remove thành công, đã xóa file và in ra :
        printf("Delete file successful   !!! \n");
    }else{
        printf("Error: Can't not delete file \n");                      // nếu hàm remove thực hiện không thành công thì in ra
    }
    return(0);
}