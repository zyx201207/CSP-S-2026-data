#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1;
    string s1;
    string c2;
    string s2;
    cin>>c1>>s1>>c2>>s2;
    int che1=int(int(c1[0]-'0')*10+int(c1[1]-'0'));
    int che2=int(int(c2[0]-'0')*10+int(c2[1]-'0'));
    //cout<<int(c1[1]-'0')<<" "<<int(c2[1]-'0')<<endl;
    bool flag1=0,flag2=0;
    if(che1==che2){
        cout<<1;
    }
    else{
        cout<<0;
        flag1=1;
    }
    if(flag1==1){
        cout<<"000";
        return 0;
    }
    int pai1=int((s1[0]-'0')*10+(s1[1]-'0'));
    int pai2=int((s2[0]-'0')*10+(s2[1]-'0'));
    //cout<<pai1<<" "<<pai2<<endl;
    if(pai1==pai2){
        cout<<1;
    }
    else{
        cout<<0;
        flag2=1;
    }
    if(flag2==1){
        cout<<"00";
        return 0;
    }
    char wei1=s1[2];
    char wei2=s2[2];
    bool flag=0;
    if((wei1>='A' && wei1<='C' && wei2>='A' && wei2<='C') || (wei1>='D' && wei2>='D')){
        cout<<1;
    }
    else{
        cout<<0;
        flag=1;
    }
    if(flag==1){
        cout<<0;
        return 0;
    }
    else{
        if(wei1>='D' && wei2>='D'){
            cout<<1;
        }
        else if((wei1=='A' && wei2=='C') || (wei2=='A' && wei1=='C')){
            cout<<0;
        }
        else{
            cout<<1;
        }
    }
    return 0;
}
