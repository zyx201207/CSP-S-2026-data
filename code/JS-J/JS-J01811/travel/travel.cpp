#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m,x,y,ca,cb;
    char a[10],b[10];
    cin>>n;
    for(int i=1;i<=3;i++) cin>>a[i];
    x=(a[1]-'0')*10+a[2]-'0';
    cin>>m;
    for(int i=1;i<=3;i++) cin>>b[i];
    y=(b[1]-'0')*10+b[2]-'0';
    if(n!=m){
        cout<<"0000"<<'\n';
    }else{
        if(x!=y){
            cout<<"1000"<<'\n';
        }else{
            if((a[3]=='D'&&b[3]=='F')||(a[3]=='F'&&b[3]=='D')||((a[3]>='A'&&a[3]<='C')&&(b[3]>='A'&&b[3]<='C'))){
                 if((a[3]=='D'&&b[3]=='F')||(a[3]=='F'&&b[3]=='D')||abs(a[3]-b[3])==1){
                      cout<<"1111"<<'\n';
                 }else{
                     cout<<"1110"<<'\n';
                 }
            }else{
                cout<<"1100"<<'\n';
            }
        }
    }
    return 0;
}
