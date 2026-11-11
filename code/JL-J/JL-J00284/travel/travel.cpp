#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int e=0;
    string a,b,n,m;
    char a1,b1;
    cin>>a>>n>>b>>m;
    if(a==b){
        e+=1000;
        if(n[0]==m[0] && n[1]==m[1]){
            e+=100;
            a1=n[2];
            b1=m[2];
            if(a1<='C' && b1<='C' || a1>='E' && b1>='E'){
                e+=10;
                if(a1-b1==-1 || a1-b1==1)e+=1;
            }
        }
    }
    cout<<e;
    return 0;
}
