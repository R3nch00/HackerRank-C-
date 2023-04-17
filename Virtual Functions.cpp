#include <bits/stdc++.h>
using namespace std;
static int StudentId,ProfessorId = 0;
class Person{
    public:
        string name;int age;
        virtual void getdata(){
            cin>>name>>age;
        }
        virtual void putdata(){
            cout<<name<<" "<<age<<" ";
        }
};
class Student:public Person{
    public:
        int id,marks[6];
        Student(){
            StudentId ++;
        }
        void getdata(){
            Person::getdata();
            for(int i=0;i<6;++i){
                cin>>marks[i];
            }
            id=StudentId;
        }
        void putdata(){
            Person::putdata();
            cout<<this->sum()<<" "<<id<<endl;
        }
        int sum(){
            int sum=0;
            for(int i=0;i<6;++i){
                sum+=marks[i];
            }
            return sum;
        }
};
class Professor:public Person{
    public:
        int publications,id;
    Professor(){
            ProfessorId ++;
        }
    void getdata(){
            Person::getdata();
            cin>>publications;
            this->id=ProfessorId;
        }
    void putdata(){
            Person::putdata();
            cout<<publications<<" "<<id<<endl;
        }
};
int main(){
    int n,val;
    cin>>n;
    Person *per[n];
    for(int i=0;i<n;i++){
        cin>>val;
        if(val==1){
            per[i]=new Professor;
        }
        else per[i]=new Student;
        per[i]->getdata();
    }
    for(int i=0;i<n;i++)
        per[i]->putdata();

    return 0;
}
