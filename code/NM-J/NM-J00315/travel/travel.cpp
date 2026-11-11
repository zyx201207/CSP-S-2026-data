#include<bits/stdc++.h>
using namespace std;
int a,b;
string n,m,c,d,g,h;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>n>>b>>m;
    c=c+n[0]+n[1];
    d=d+m[0]+m[1];
    g=n[2];
    h=m[2];
    if(a==b){
        cout<<'1';
    }else{
        cout<<'0';
    }
    if(a==b&&d==c){
        cout<<'1';
    }else{
        cout<<'0';
    }
    if(a==b&&d==c&&((g[0]=='D'&&h[0]=='F')||(g[0]=='F'&&h[0]=='D')||(g[0]>='A'&&g[0]<='C'&&h[0]>='A'&&h[0]<='C'))){
        cout<<'1';
    }else{
        cout<<'0';
    }
    if(a==b&&c==d&&((g[0]+1==h[0]&&h[0]!='D')||(g[0]==h[0]+1&&g[0]!='D'))){
        cout<<'1';
    }else{
        cout<<'0';
    }
    return 0;
}
