/*************************
//
//  main.cpp 主函数程序文件
//  ZNING ZNSQL
//
//  Created by ZNing on 15/7/21.
//  Copyright (c) 2015年 ZNing. All rights reserved.
//
*************************/

#include "head.h"
#include "Lexer.h"

void Select();
int main()
{
    cout<<"ZNING ZNSQL [Verson 0.0.0001]\n(c) 2015 ZNING of CISE of SDUST. Copyright."<<endl;
    cout<<"Author: ZHANG Ning StuNo: 201301050439"<<endl;
    cout<<"\tGENG Sifan StuNo: 201301050408\n"<<endl;
    while (cout << "znsql> ")
    {
        Select();
    }
    return 0;
}
