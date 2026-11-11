 #include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,aa,bb,cc;
    long long d,dd;
    bool is=0;
    cin>>a>>b>>aa>>bb;
    d=int(b[2])-64;
    dd=int(bb[2])-64;
    if(a==aa)cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(b[0]==bb[0]&&b[1]==bb[1])cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if((d<=3&&dd<=3)||(d>3&&dd>3)){
        cout<<1;
        is=1;
    }
    else{
        cout<<"00";
        return 0;
    }
    if((d-1==dd||d+1==dd)&&is)cout<<1;
    else cout<<0;
    return 0;
}
