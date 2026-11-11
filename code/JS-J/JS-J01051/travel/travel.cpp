#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c;
    string b,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    int x=b[0],y=b[1],n=d[0],m=d[1];
    if(x==n&&y==m){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    char ch1=b[2],ch2=d[2];
    if(((ch1=='A'||ch1=='B'||ch1=='C')&&(ch2=='A'||ch2=='B'||ch2=='C'))||((ch1=='D'||ch1=='F')&&((ch2=='D'||ch2=='F')))){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }
    if((ch1=='C'&&ch2=='D')||(ch2=='C'&&ch1=='D')){
        cout<<"0";
    }else{
        if(ch1-ch2==1||ch2-ch1==1){
            cout<<"1";
        }else{
            cout<<"0";
        }
    }
    return 0;
}
