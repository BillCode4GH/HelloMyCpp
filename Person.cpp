/*
  Name: C++ 第三次实验 
  Copyright: billcode
  Author: 余文艳 
  Date: 26/04/13 15:39
  Description: 定义一个完整的人员类 
*/
#include <iostream>
#include <cstring>
using namespace std;
class Person{
      private:
              char m_strName[20];
              int m_nAge;
              int m_nSex;
      public:
             Person();//构造函数
             Person(const char *name,int age,char sex);//构造函数
             Person(const Person &p);//拷贝构造函数
             ~Person()//析构函数
             {
               cout<<"Now destroying the instance of Person"<<endl;
                                 } 
             void SetName(const char *name);
             void SetAge(int age);
             void SetSex(char sex);
             char* GetName();
             int GetAge();
             char GetSex();
             void ShowPerson();
      };
      Person::Person():m_nAge(0),m_nSex(0){//构造函数 
             strcpy(m_strName,"XXX");
      }
      Person::Person(const char *name,int age,char sex):m_nAge(age),m_nSex(sex=='m'?0:1){//构造函数 
              strcpy(m_strName,name);             
                           
                           }
      Person::Person(const Person &p):m_nAge(p.m_nAge),m_nSex(p.m_nSex){//拷贝构造函数 
              strcpy(m_strName,p.m_strName);             
                           }
      void Person::SetName(const char *name){
           strcpy(m_strName,name);
           
           }
      void Person::SetAge(int age){
           m_nAge=age;
           }
      void Person::SetSex(char sex){
           m_nSex=sex=='m'?0:1;
           }
      char* Person::GetName(){
            return m_strName;
            }
      int Person::GetAge(){
          return m_nAge;
           
          }
      char Person::GetSex(){
           
           return (m_nSex==0?'m':'f');
           }
      void Person::ShowPerson(){
           
           cout<<GetName()<<'\t'<<GetAge()<<'\t'<<GetSex()<<endl;
           }
      int main(){
          int delay;
          Person *p1,*p2;//声明两个指向对象的指针
          p1=new Person;//动态生成一个Person对象
          cout<<"Perso1:\t";
          p1->ShowPerson();
          p1->SetAge(19);
          cout<<"Person1:\t";
          p1->ShowPerson();
          p2=new Person("zhang3",19,'m');//动态生成一个Person对象 
          cout<<"Person2:\t";
          p2->ShowPerson();
          *p1=*p2; //对象之间的赋值 
          cout<<"Person2:\t";
          p2->ShowPerson();
          delete p1;//释放p1指向对象所占的空间 
          delete p2;//释放p2指向对象所占的空间
          cin>>delay;
          
          return 0; 
          }
