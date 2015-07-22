/*************************
//
//  selecter.cpp 选择函数程序文件
//  ZNING ZNSQL
//
//  Created by ZNing on 15/7/21.
//  Copyright (c) 2015年 ZNing. All rights reserved.
//
*************************/

#include "head.h"
#include "Table.h"
#include "SQL.h"
#include "WorkFunction.h"

#define MAX 1000

void upper_change(char *Com)
{
    char temp[MAX];
    int i;
    for (i = 0; Com[i] != '\0'; i++)
    {
        if (Com[i] <= 90 && Com[i] >= 65)
            temp[i] = Com [i] + 32;
        else  temp[i] = Com [i];
    }
    temp[i] = '\0';
    strcpy(Com , temp);
}

void Select()
{
    char s[1000];
    gets(s);
    upper_change(s);///There, we change the string alphabat to upper.
    //puts(s);///转换检测
    SQL *sql=new SQL(s);
    if (sql->Get(sql->GetSize()-1) != ";") {cout<<"plz use ; to the end."<<endl; return ;}
    if (sql->Get(0) == "exit"){cout<<"ByeBye~"<<endl; exit(0);}
    if (!sql->Judge()) return ;
    if (sql->Get(0) == "create" && sql->Get(1) == "table")
        createTable(sql);//create table s (num int ,name char(10))
    else if(sql->Get(0) == "insert" && sql->Get(1) == "into" && sql->Get(3) == "values")
        insertRecord(sql);//insert into s values ()
    else if (sql->Get(0) == "show")
        showTable(sql->Get(1)); //show s
    else if (sql->Get(0) == "drop" && sql->Get(1) == "table")
        dropTable (sql->Get(2));//drop table s
    else if (sql->Get(0) =="alter" && sql->Get(1) == "table")
        alterTable (sql);//alter table s (add name type)/(drop name type)
    else if (sql->Get(0) =="delete" && sql->Get(1) == "from" && sql->Get(3) == "while")
        deleteRecord(sql);//delete from s while name = name1
    else cout << "The code is error!" << endl;
}
