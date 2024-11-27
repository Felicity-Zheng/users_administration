#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
void enterSystem(){
    cout<<"      __________________________\n";
    cout<<"     |     **学生信息管理系统**   |\n";
    cout<<"     |      请选择您所需的操作：   |\n";
    cout<<"     |   数据添加:输入1并按回车键  |\n";
    cout<<"     |   数据删除:输入2并按回车键  |\n";
    cout<<"     |   数据输出:输入3并按回车键  |\n";
    cout<<"     |   数据修改:输入4并按回车键  |\n";
    cout<<"     |   数据查询:输入5并按回车键  |\n";
    cout<<"     |   系统退出:输入0并按回车键  |\n";
    cout<<"     |                          |\n";
    cout<<"     |_______请选择一个操作:______|\n";
}
class Student{
public:
    string name,sex,group,prof,num;
    string info[5]={"姓名:","学号:","性别:","组别:","专业班级:"};
    vector<string> arr;
    void setInfo(){             //郑教练把这里有关文件操作的全部删掉，统一由新增的方法处理
//        ifstream fin;
//        fin.open("data.txt",ios::in);
//        ofstream fout;
//        fout.open("data.txt",ios::out);
        cout<<"请输入姓名:"<<endl;
        cin>>name;
//        fout<<name<<"\n";
        arr.push_back(name);
        cout<<"请输入学号:"<<endl;
        cin>>num;
//        fout<<num<<"\n";
        arr.push_back(num);
        cout<<"请输入性别:"<<endl;
        cin>>sex;
//        fout<<sex<<"\n";
        arr.push_back(sex);
        cout<<"请输入组别:"<<endl;
        cin>>group;
//        fout<<group<<"\n";
        arr.push_back(group);
        cout<<"请输入专业班级:"<<endl;
        cin>>prof;
//        fout<<prof<<"\n";
        arr.push_back(prof);
//        fout.close();
        cout<<endl;
        cout<<"信息添加成功！显示如下："<<endl;
        cout<<endl;
        cout<<"\t"<<info[0]<<"\t"<<info[1]<<"\t"<<info[2]<<"\t"<<info[3]<<"\t"<<info[4]<<endl;
        cout<<"\t";
        cout<<name<<"\t"<<num<<"\t"<<sex<<"\t"<<group<<"\t"<<prof<<"\t";    //直接输出从终端输入的信息，无需下面从txt文件中读取
//        int i=0;
//        string buf;
//        while(getline(fin,buf)){
//            cout<<buf<<"\t";
//            i+=1;
//        }
        cout<<endl;
//        fin.close();
    }

    void del(){
        string name;
        cout<<"请输入要删除信息的人员姓名:"<<endl;
        cin>>name;
        for(size_t i=0;i<arr.size();i++){
            if(arr[i]==name){
                cout<<"被删除人员信息为："<<endl;
                cout<<info[0]<<arr[i]<<endl;
                arr.erase(arr.begin()+i);
                cout<<info[1]<<arr[i]<<endl;
                arr.erase(arr.begin()+i);
                cout<<info[2]<<arr[i]<<endl;
                arr.erase(arr.begin()+i);
                cout<<info[3]<<arr[i]<<endl;
                arr.erase(arr.begin()+i);
                cout<<info[4]<<arr[i]<<endl;
                arr.erase(arr.begin()+i);
                cout<<endl;
                break;
            }
        }
        cout<<"删除后的人员信息为:"<<endl;
        cout<<endl;
        cout<<"\t"<<info[0]<<"\t"<<info[1]<<"\t"<<info[2]<<"\t"<<info[3]<<"\t"<<info[4]<<endl;
        for(size_t i=0;i<arr.size();i++){
            cout<<"\t"<<arr[i];
            if(i%5==4){
                cout<<endl;
            }
        }
        cout<<endl;
    }

    void outPut(){
        string target,change;
        int a;
        string name;
        cout<<"目前竞培营所有人员信息为:"<<endl;
        cout<<endl;
        cout<<"\t"<<info[0]<<"\t"<<info[1]<<"\t"<<info[2]<<"\t"<<info[3]<<"\t"<<info[4]<<endl;
        for(size_t i=0;i<arr.size();i++){
            cout<<"\t"<<arr[i];
            if(i%5==4){
                cout<<endl;
            }
        }
        cout<<endl;
    }

    void modify(){
        string target,change;
        int a;
        string name;
        cout<<"输入要修改信息的人员姓名:"<<endl;
        cin>>name;
        for(size_t i=0;i<arr.size();i++){
            if(arr[i]==name){
                cout<<"请输入该人员要修改的信息:"<<endl;
                cin>>target;
                if(target=="姓名"){
                    a=0;
                }else if(target=="学号"){
                    a=1;
                }else if(target=="性别"){
                    a=2;
                }else if(target=="组别"){
                    a=3;
                }else if(target=="专业班级"){
                    a=4;
                }
                cout<<info[a];
                cin>>change;
                arr[i+a]=change;
                cout<<"该人员修改后的信息为:"<<endl;
                cout<<endl;
                cout<<"\t"<<info[0]<<"\t"<<info[1]<<"\t"<<info[2]<<"\t"<<info[3]<<"\t"<<info[4]<<endl;
                cout<<"\t";
                for(size_t j=i;j<i+5;j++){
                    cout<<arr[j]<<"\t";
                }
                break;
            }
        }
        cout<<endl;
    }

    void check(){
        string name;
        cout<<"输入要查询的人员姓名:"<<endl;
        cin>>name;
        for(size_t i=0;i<arr.size();i++){
            if(arr[i]==name){
                cout<<"\t"<<info[0]<<"\t"<<info[1]<<"\t"<<info[2]<<"\t"<<info[3]<<"\t"<<info[4]<<endl;
                cout<<"\t";
                for(int j=i;j<i+5;j++){
                    cout<<arr[j]<<"\t";
                }
                break;
            }
        }
        cout<<endl;
    }

    void readfromtext(){                        //郑教练增加的方法
        string buf,word;
        int start_index,finish_index;
        ifstream fin;                           //定义输入流文件
        fin.open("data.txt",ios::in);              //打开数据流文件txt
        while(getline(fin,buf)){                    //逐行读取数据到buf中
            start_index=0;
            for(size_t i=0;i<5;i++){          //此循环功能：将一行由TAB隔开的5个子串，逐个读入到arr中
                finish_index=buf.find("\t");    //查找第一个tab在buf中的位置
                word = buf.substr(start_index,finish_index-start_index);    //截取首个子串：substr（int a,int b）a表示子串首个字符在buf中的位置，b表示要截取子串的长度
                arr.push_back(word);        //子串读入到arr中
                buf = buf.substr(finish_index+1,buf.size());        //把buf中已经被截取的首个子串删掉，形成新的buf，使得下次被读取的首个子串是原串buf的第二、三、四、五个子串
            }
        }
    }

    void writetotext(){                          //郑教练增加的方法
        ofstream fout("data.txt",ios::trunc);   //先清空所有数据，否则txt文件中的数据会多于容器中的数据
        for(size_t i=0;i<arr.size();i++){       //将arr中所有的数据写入txt文件中，用tab隔开，5个数据一行
            fout<<arr[i]<<"\t";
            if(i%5==4){
                fout<<endl;
            }
        }
    }

};
int main(){
    int operate;
    Student student;
    student.readfromtext();             //郑教练增加的：系统运行前将txt文件中的数据读入容器arr中
    while(true){
        enterSystem();
        cin>>operate;
        if(operate==1){
            student.setInfo();
        }else if(operate==2){
            student.del();
        }else if(operate==3){
            student.outPut();
        }else if(operate==4){
            student.modify();
        }else if(operate==5){
            student.check();
        }else if(operate==0){
            student.writetotext();      //郑教练增加的：在退出前将容器arr中的数据写入txt文件
            cout<<"您已成功退出系统！";
            return 0;
        }
    }
    return 0;
}
