// chèn 1 số vào chuỗi //



// #include <stdio.h>
// #include <stdlib.h>


// int* themPhanTu(int* arr, int kichThuoc, int phanTuMoi, int viTri) {

//     int* mangMoi = (int*)malloc((kichThuoc + 1) * sizeof(int));

  
//     for (int i = 0, j = 0; i < kichThuoc + 1; i++) {
//         if (i == viTri) {
//             mangMoi[i] = phanTuMoi;
//         } else {
//             mangMoi[i] = arr[j++];
//         }
//     }

//     free(arr);

//     return mangMoi;
// }

// int main() {
//     int kichThuoc = 5;
//     int arr[] = {1, 2, 3, 4, 5};

//     int* mangMoi = (int*)malloc(kichThuoc * sizeof(int));
//     for (int i = 0; i < kichThuoc; i++) {
//         mangMoi[i] = arr[i];
//     }


//     int phanTuMoi = 6;
//     int viTri = 2;
//     mangMoi = themPhanTu(mangMoi, kichThuoc, phanTuMoi, viTri);
//     kichThuoc++;


//     printf("Mảng sau khi thêm phần tử: ");
//     for (int i = 0; i < kichThuoc; i++) {
//         printf("%d ", mangMoi[i]);
//     }


//     free(mangMoi);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// // Định nghĩa cấu trúc cho một nút trong danh sách liên kết
// struct Node {
//     char name[50];
//     int id;
//     struct Node* next;
// };

// // Hàm tạo nút mới
// struct Node* createNode(char* name, int id) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     strcpy(newNode->name, name);
//     newNode->id = id;
//     newNode->next = NULL;
//     return newNode;
// }

// // Hàm thêm nút vào cuối danh sách liên kết
// void appendNode(struct Node** head, char* name, int id) {
//     struct Node* newNode = createNode(name, id);
//     if (*head == NULL) {
//         *head = newNode;
//         return;
//     }

//     struct Node* temp = *head;
//     while (temp->next != NULL) {
//         temp = temp->next;
//     }
//     temp->next = newNode;
// }

// // Hàm hiển thị danh sách liên kết
// void displayList(struct Node* head) {
//     struct Node* temp = head;
//     while (temp != NULL) {
//         printf("Tên: %s, ID: %d\n", temp->name, temp->id);
//         temp = temp->next;
//     }
// }

// // Hàm giải phóng bộ nhớ của danh sách liên kết
// void freeList(struct Node* head) {
//     struct Node* temp;
//     while (head != NULL) {
//         temp = head;
//         head = head->next;
//         free(temp);
//     }
// }

// int main() {
//     struct Node* head = NULL;

//     // Thêm sinh viên vào danh sách
//     appendNode(&head, "Nguyen Van A", 101);
//     appendNode(&head, "Tran Thi B", 102);
//     appendNode(&head, "Le Van C", 103);

//     // Hiển thị danh sách sinh viên
//     printf("Danh sách sinh viên:\n");
//     displayList(head);

//     // Giải phóng bộ nhớ của danh sách
//     freeList(head);

//     return 0;
// }
#define max 1000
int queue[max];
int front = -1;
int rear = -1;
void enqueue(int element){
    if( rear == max -1 )
    {
        printf(" full");
        return ;
    }
    if( front == -1 )
    {
        front = 0;
    }
    rear ++;
    queue[rear] = element;
}
int dequeue()
{
    if(front == -1 || front > rear ){
        printf(" empty");
        return -1;
    }
    int element = queue[front];
    front ++;
    return element;
}
int main ()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("%d \n",dequeue());
    printf("%d \n",dequeue());
    printf("%d \n",dequeue());
    printf("%d",dequeue());
    return 0;
// husadnagsdhsadjaslda;dka
}