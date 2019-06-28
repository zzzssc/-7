//
//  main.cpp
//  文件传输7
//
//  Created by s20181106119 on 2019/6/28.
//  Copyright © 2019 s20181106119. All rights reserved.
//

#define total 5  //学生人数的宏定义
#include<iostream>
#include<fstream>
#include<algorithm>
#include<iomanip>
using namespace std;
struct student{
    char name1[10];       //学生姓名
    char number[50];      //学号
    char  colleage[50];   //学院
    char  speciality[50];   //专业
    double ave;
    double score[10];
};
struct referee{
    char name2[8];    //裁判姓名
    double score[10];    //分数
};
int compare(student  &p1,student &p2)
{
    if(p1.ave>p2.ave)
    {
        return true;
    }
    else if(p1.ave==p2.ave)
    {
        if(p1.name1-p2.name1>0)
        {
            return true ;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
int main()
{
    
    ifstream in("/Users/s20181106119/Desktop/学生信息.txt");
    struct student student[total];
    struct  referee referee[7];
    int i;
    //cout<<"1"<<endl;;
    for(i=0;i<5;i++)
    {
        in>>student[i].name1>>student[i].number>>student[i].colleage;
    }
    
    
    ifstream inf ("/Users/s20181106119/Desktop/裁判信息及分数.txt");
    //cout<<"2"<<endl;
    int l,j,sum=0;
    for(l=0;l<7;l++)
    {
        inf>>referee[l].name2;
        for(j=0;j<total;j++)
        {
            inf>>referee[l].score[j];
        }
        
    }
    
    /*for(l=0;l<7;l++)
     {
     for(j=0;j<5;j++)
     {
     cout<<referee[l].score[j]<<" ";
     }
     cout<<endl;
     }*/
    for(i=0;i<total;i++)
    {
        for(j=0;j<7;j++)
        {
            student[i].score[j]= referee[j].score[i];
        }
        
    }
    for(i=0;i<total;i++)
    {
        sort(student[i].score,student[i].score+7);
    }
    
    /*for(i=0;i<5;i++)
     {
     for(j=0;j<7;j++)
     {
     cout<<student[i].score[j]<<" ";
     
     }
     cout<<endl;
     }*/
    for(j=0;j<total;j++)
    {
        for(l=1;l<6;l++)
        {
            sum=sum+student[j].score[l];
        }
        student[j].ave=1.0*sum/5;
        sum=0;
    }
    sort(student,student+total,compare);
    
    ofstream output("/Users/s20181106119/Desktop/最终排名.txt");
    if(output.is_open())
    {
        int i;
        output<<left<<setw(21)<<"学生姓名"
        <<left<<setw(18)<<"学院"
        <<left<<setw(13)<<"学号"
        <<left<<setw(10)<<"最终成绩"<<endl;
        for(i=0;i<total;i++)
        {
            output<<left<<setw(15)<<student[i].name1
            <<left<<setw(15)<<student[i].colleage
            <<left<<setw(10)<<student[i].number
            <<left<<setw(10)<<student[i].ave<<endl;
        }
        
        output.close();
    }
}
