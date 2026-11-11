#include<bits/stdc++.h>
using namespace std;
string a,b,a1,b1;
bool flag,flag1,cmp,f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b>>a1>>b1;
    if(a==a1){
        cout<<1;
        f=true;
    }else{
        cout<<0;
        f=false;
    }
    string aa=(string)""+b[0]+b[1];
    string bb=(string)""+b1[0]+b1[1];
    if(f&&bb==aa){
        cout<<1;
        flag=true;
    }else{
        cout<<0;
        flag=false;
    }
    if(flag&&(b[2]>='A'&&b[2]<='C'&&b1[2]>='A'&&b1[2]<='C')||(b[2]>='D'&&b[2]<='F'&&b1[2]>='D'&&b1[2]<='F')){
        cout<<1;
        flag1=true;
    }else{
        cout<<0;
        flag1=false;
    }
    if(flag1){
        char ch=b[2],ch1=b1[2];
        if(b[2]>b1[2]){
            ch=b1[2];
            ch1=b[2];
        }
        if((ch=='C'&&ch1=='D')) cmp=false;
        else if((int)abs(ch-ch1)==1){
            cmp=true;
        }else{
            cmp=false;
        }



    }
    if(flag&&flag1&&cmp&&f){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
