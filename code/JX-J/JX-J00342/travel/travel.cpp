#include <bits/stdc++.h>

using namespace std;
int a[100100],s[10010];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c;
    string b,d;
    int f1=0,f2=0,f3=0,f4=0;
    cin>>a>>b>>c>>d;
    if(a==c){
        //cout<<1<<endl;
        f1=1;
        //cout<<f1<<endl;
    }
    if((b[0]+b[1])==(d[0]+d[1])&&f1){
        f2=1;
    }
    if((b[2]=='F'||b[2]=='D')&&(d[2]=='F'||d[2]=='D')&&f2){
        f3=1;
    }else if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')&&f2){
        f3=1;
    }
    if(((b[2]=='F'&&d[2]=='D')||(b[2]=='D'&&d[2]=='F'))&&f3){
        f4=1;
    }else if(((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A'))&&f3){
        f4=1;
    }else if(((b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B'))&&f3){
        f4=1;
    }
    cout<<f1<<f2<<f3<<f4;
    return 0;
}