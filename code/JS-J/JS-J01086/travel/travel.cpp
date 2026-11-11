#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    char n,m;
    bool o=0,p=0;
    cin>>a>>b>>n>>c>>d>>m;
    if(a==c){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(b==d){
        cout<<1;
        if(n=='B'||n=='A'||n=='C') o=1;
        else o=0;
        if(m=='B'||m=='A'||m=='C') p=1;
        else p=0;
        if(o==p){
            cout<<1;
        }else{
            cout<<"00";
            return 0;
        }
    }else{
        cout<<"00";
    }
    if((m==n && abs(d-b)==1) || (d==b && abs(m-n)==1)){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
