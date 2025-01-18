#include <stdio.h>
#include <stdlib.h> /*malloc函数所在库*/

/*定义顺序表最大长度*/
#define MAXLEGNTH 100

 /*将ElemType定义为int，便于后期修改数据类型*/
typedef int ElemType;

/*定义顺序表结构体*/
typedef struct Seqlist
{
    ElemType data[MAXLEGNTH];
    int length;
}Seqlist;

/*顺序表初始化*/
void Seqlist_Init(Seqlist *L){
    L->length = 0;
    printf("Seqlist Initialized!\r\n");
}


/*顺序表新增元素*/
int Seqlist_Append(Seqlist *L, ElemType element){
    if(L->length == MAXLEGNTH){
        printf("err:Seqlist Full!");
        return 0;
    }
    L->data[L->length] = element;
    L->length ++;
    printf("New element \"%d\" Appended!\r\n", element);
    return 1;
}

/*遍历顺序表并打印每个元素*/
void Seqlist_Elems(Seqlist L){
    int i;
    if(L.length == 0){
        printf("err:Seqlist Empty!\r\n");
    }else{
        for(i=0; i<L.length; i++){
            printf("%d ",L.data[i]);
        }
        printf("\r\n");
    }
}


/*顺序表指定位置插入元素(pos从1开始计)*/
int Seqlisty_Insert(Seqlist *L, int pos, ElemType element){
    if(pos < 1 || pos > L->length+1){
        printf("err:Pos Error!\r\n");
        return 0;
    }else if(L->length == MAXLEGNTH){
        printf("err:Seqlist Full!\r\n");
        return 0;
    }else{
        int i;
        /*pos位置后的所有元素后移一个单元*/
        for(i=L->length; i>pos-1; i--){
            L->data[i] = L->data[i-1];
        }
        /*将新元素添加至pos位置上并使顺序表长度+1*/
        L->data[pos-1] = element;
        L->length++;

        printf("Element \"%d\" Inserted at pos %d.\r\n",element,pos);
        return 1;
    }
}


/*顺序表删除元素,并将删除的元素存入*element*/
int Seqlist_Delete(Seqlist *L, int pos, ElemType *element){
    if(pos < 1 || pos > L->length){
        printf("Pos err!\r\n");
        return 0;
    }else if(L->length == 0){
        printf("err:SeqList Empty!\r\n");
    }else{
        *element = L->data[pos-1]; /*将删除的元素存入*element*/
        int i;
        for(i=pos-1; i< L->length-1; i++){
            L->data[i] = L->data[i+1];
        }
        L->length--;

        printf("Element \"%d\" at pos %d is deleted.\r\n",*element,pos);
        return 1;
    }
}


/*返回指定元素在顺序表中第一次出现的位置*/
int Seqlist_Find(Seqlist *L, ElemType element){
    int i;
    for(i=0; i<= L->length; i++){
        if(L->data[i] == element){
            printf("Element \"%d\" at pos %d.\r\n",element,i+1);
            return i+1;
        }
    }
    printf("Element \"%d\" Not Found!\r\n", element);
    return 0;
}


Seqlist sqlist;

int main(){
    ElemType delete_data;
    Seqlist_Init(&sqlist);
    
    Seqlist_Append(&sqlist, 22);
    Seqlist_Append(&sqlist, 34);
    Seqlist_Append(&sqlist, 57);
    Seqlist_Elems(sqlist);

    Seqlisty_Insert(&sqlist, 4, 255);
    Seqlist_Elems(sqlist);

    Seqlist_Delete(&sqlist, 3, &delete_data);
    printf("deleted element is %d.\r\n",delete_data);
    Seqlist_Elems(sqlist);

    Seqlist_Find(&sqlist, 255);
    return 0;
}
