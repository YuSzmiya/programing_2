#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DATA_CREATE_EXIT (-1)

/**
* @struct data
* @brief リスト構造体
*
* @typedef DATA
* @brief リスト構造体
*/
typedef struct data{
    int id; // 学籍番号
    char name[20];  //名前
    struct data *next;  //次の要素へのポインタ
} DATA;

// グローバル変数
DATA *head = NULL;
DATA *tail = NULL;

/**
 * @brief リストを作成する
 * @return リストの先頭ポインタ
*/
static DATA *createData(void);

/**
 * @brief リストの内容を表示する
 * @param[in] head リストの先頭ポインタ
*/
static void printData(DATA *head);

/**
 * @brief リストを昇順ソートする
 * @param[in] head リストの先頭ポインタ
 * @return リストの先頭ポインタ
*/
static DATA *sortData(DATA *head);

/**
 * @brief リストを削除する
 * @param[in] head リストの先頭ポインタ
 * @retval NULL : リスト消去成功
 * @retval Others : リスト消去失敗
*/
static DATA * deleteData(DATA *head);

int main (void){
    DATA *head;
    int input;
    head = NULL;

    while (1)
    {
        printf("-------------操作方法------------------\n");
        printf("1 : データ入力\n");
        printf("2 : 表示して！\n");
        printf("3 : おわり\n");
        printf("----------------------------------------\n");

        printf("コマンド：");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            head = createData();
            break;
        case 2:
            head = sortData(head);
            printData(head);
        case 3:
            head = deleteData(head);
            break;
        default:
            printf("意味わかんない\n");
            break;
        }
    }    return 0;
}
static DATA *createData(void){
    DATA *head, *temp, *prev;
    char buf[20], name[20];
    int id, count;

    printf("入力してね！（終わる時は %d を送って）\n", DATA_CREATE_EXIT);

    head = NULL;
    temp = NULL;
    prev = NULL;

    while (1)
    {
        printf("番号教えて：");
        fgets(buf, sizeof(buf), stdin);
        id = atoi(buf);

        if (id == DATA_CREATE_EXIT)
        {
            break;
        }

        temp = (DATA *)malloc(sizeof(DATA));
        temp->id = id;

        printf("名前は何？:");
        fgets(name, sizeof(name), stdin);
        strcpy(temp->name, name);
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
        }else{
            prev->next = temp;
        }
        prev = temp;
    }
    printf("\n入力お疲れ様！！\n");
    return head;
}
static void printData(DATA *head){
    DATA *temp;
    int count;
    temp = head;

    if ((head == NULL) && (tail == NULL))
    {
        printf("誰もいないみたい");
    }

    printf("\n表示するね。\n");
    temp = head;
    count = 0;

    printf("-------------------------------------\n");

    while (temp != NULL)
    {
        printf("学籍番号    : %d\n", temp->id);
        printf("名前        : %s\n", temp->name);

        temp = temp->next;
        count++;
    }
    return;
}
static DATA *sortData(DATA *head){
    DATA *headUnsorted, *headSorted;
    DATA *max, *prevMax, *prevComp;

    printf("並び替え中...\n");
    headUnsorted = head;
    headSorted = NULL;

    while (headUnsorted != NULL)
    {
        max = headUnsorted;
        prevMax = NULL;
        prevComp = headUnsorted;

        while (prevComp->next != NULL)
        {
            if ((prevComp->next)->id > max->id)
            {
                max = prevComp->next;
                prevMax = prevComp;
            }
            prevComp = prevComp->next;
        }
        if (prevMax == NULL)
        {
            headUnsorted = max->next;
        }else{
            prevMax->next = max->next;
        }

        if (headSorted == NULL)
        {
            headSorted = max;
            max->next = NULL;
        }else{
            max->next = headSorted;
            headSorted = max;
        }
    }
    return headSorted;
}
static DATA *deleteData(DATA *head){
    DATA *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}