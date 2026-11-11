#include<iostream>
#include<string>
using namespace std;
string c1,s1,c2,s2;
bool chexiang(string che1,string che2){
    if(che1==che2) return true;
    else return false;
}
bool paishu(string line1,string line2){
    if(line1[0]==line2[0]&&line1[1]==line2[1]) return true;
    else return false;
}
bool guodao(string line1,string line2){
    if(line1[2]<='C'&&line2[2]<='C'){
       return true;
    }
    if(line1[2]>='D'&&line2[2]>='D'){
        return true;
    }
    return false;
}
bool xianglin(string line1,string line2){
    if(line1[2]=='A'&&line2[2]!='B'){
        return false;
    }
    if(line1[2]=='B'&&(line2[2]!='A'&&line2[2]!='C')){
        return false;
    }//zhe li pan duan cha dian chu shi
    if(line1[2]=='C'&&line2[2]!='B'){
        return false;
    }
    if(line1[2]=='D'&&line2[2]!='F'){
        return false;
    }
    if(line1[2]=='F'&&line2[2]!='D'){
        return false;
    }
    return true;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(chexiang(c1,c2)){
        if(paishu(s1,s2)){
            if(guodao(s1,s2)){
                if(xianglin(s1,s2)){
                    cout<<"1111";
                    return 0;
                }else{
                    cout<<"1110";
                    return 0;
                }
            }else{
                cout<<"1100";
                return 0;
            }
        }else{
            cout<<"1000";
            return 0;
        }
    }else{
        cout<<"0000";
        return 0;
    }
    return 0;
}
