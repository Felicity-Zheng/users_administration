#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
void enterSystem(){
    cout<<"      __________________________\n";
    cout<<"     |     **ѧ����Ϣ����ϵͳ**   |\n";
    cout<<"     |      ��ѡ��������Ĳ�����   |\n";
    cout<<"     |   �������:����1�����س���  |\n";
    cout<<"     |   ����ɾ��:����2�����س���  |\n";
    cout<<"     |   �������:����3�����س���  |\n";
    cout<<"     |   �����޸�:����4�����س���  |\n";
    cout<<"     |   ���ݲ�ѯ:����5�����س���  |\n";
    cout<<"     |   ϵͳ�˳�:����0�����س���  |\n";
    cout<<"     |                          |\n";
    cout<<"     |_______��ѡ��һ������:______|\n";
}
class Student{
public:
    string name,sex,group,prof,num;
    string info[5]={"����:","ѧ��:","�Ա�:","���:","רҵ�༶:"};
    vector<string> arr;
    void setInfo(){             //֣�����������й��ļ�������ȫ��ɾ����ͳһ�������ķ�������
//        ifstream fin;
//        fin.open("data.txt",ios::in);
//        ofstream fout;
//        fout.open("data.txt",ios::out);
        cout<<"����������:"<<endl;
        cin>>name;
//        fout<<name<<"\n";
        arr.push_back(name);
        cout<<"������ѧ��:"<<endl;
        cin>>num;
//        fout<<num<<"\n";
        arr.push_back(num);
        cout<<"�������Ա�:"<<endl;
        cin>>sex;
//        fout<<sex<<"\n";
        arr.push_back(sex);
        cout<<"���������:"<<endl;
        cin>>group;
//        fout<<group<<"\n";
        arr.push_back(group);
        cout<<"������רҵ�༶:"<<endl;
        cin>>prof;
//        fout<<prof<<"\n";
        arr.push_back(prof);
//        fout.close();
        cout<<endl;
        cout<<"��Ϣ��ӳɹ�����ʾ���£�"<<endl;
        cout<<endl;
        cout<<"\t"<<info[0]<<"\t"<<info[1]<<"\t"<<info[2]<<"\t"<<info[3]<<"\t"<<info[4]<<endl;
        cout<<"\t";
        cout<<name<<"\t"<<num<<"\t"<<sex<<"\t"<<group<<"\t"<<prof<<"\t";    //ֱ��������ն��������Ϣ�����������txt�ļ��ж�ȡ
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
        cout<<"������Ҫɾ����Ϣ����Ա����:"<<endl;
        cin>>name;
        for(size_t i=0;i<arr.size();i++){
            if(arr[i]==name){
                cout<<"��ɾ����Ա��ϢΪ��"<<endl;
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
        cout<<"ɾ�������Ա��ϢΪ:"<<endl;
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
        cout<<"Ŀǰ����Ӫ������Ա��ϢΪ:"<<endl;
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
        cout<<"����Ҫ�޸���Ϣ����Ա����:"<<endl;
        cin>>name;
        for(size_t i=0;i<arr.size();i++){
            if(arr[i]==name){
                cout<<"���������ԱҪ�޸ĵ���Ϣ:"<<endl;
                cin>>target;
                if(target=="����"){
                    a=0;
                }else if(target=="ѧ��"){
                    a=1;
                }else if(target=="�Ա�"){
                    a=2;
                }else if(target=="���"){
                    a=3;
                }else if(target=="רҵ�༶"){
                    a=4;
                }
                cout<<info[a];
                cin>>change;
                arr[i+a]=change;
                cout<<"����Ա�޸ĺ����ϢΪ:"<<endl;
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
        cout<<"����Ҫ��ѯ����Ա����:"<<endl;
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

    void readfromtext(){                        //֣�������ӵķ���
        string buf,word;
        int start_index,finish_index;
        ifstream fin;                           //�����������ļ�
        fin.open("data.txt",ios::in);              //���������ļ�txt
        while(getline(fin,buf)){                    //���ж�ȡ���ݵ�buf��
            start_index=0;
            for(size_t i=0;i<5;i++){          //��ѭ�����ܣ���һ����TAB������5���Ӵ���������뵽arr��
                finish_index=buf.find("\t");    //���ҵ�һ��tab��buf�е�λ��
                word = buf.substr(start_index,finish_index-start_index);    //��ȡ�׸��Ӵ���substr��int a,int b��a��ʾ�Ӵ��׸��ַ���buf�е�λ�ã�b��ʾҪ��ȡ�Ӵ��ĳ���
                arr.push_back(word);        //�Ӵ����뵽arr��
                buf = buf.substr(finish_index+1,buf.size());        //��buf���Ѿ�����ȡ���׸��Ӵ�ɾ�����γ��µ�buf��ʹ���´α���ȡ���׸��Ӵ���ԭ��buf�ĵڶ��������ġ�����Ӵ�
            }
        }
    }

    void writetotext(){                          //֣�������ӵķ���
        ofstream fout("data.txt",ios::trunc);   //������������ݣ�����txt�ļ��е����ݻ���������е�����
        for(size_t i=0;i<arr.size();i++){       //��arr�����е�����д��txt�ļ��У���tab������5������һ��
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
    student.readfromtext();             //֣�������ӵģ�ϵͳ����ǰ��txt�ļ��е����ݶ�������arr��
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
            student.writetotext();      //֣�������ӵģ����˳�ǰ������arr�е�����д��txt�ļ�
            cout<<"���ѳɹ��˳�ϵͳ��";
            return 0;
        }
    }
    return 0;
}
