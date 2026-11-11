#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<0<<0<<0<<0;
        return 0;
    } else{
        cout<<1;
    }
    if(b[0]!=d[0] || b[1]!=d[1]){
        cout<<0<<0<<0;
        return 0;
    } else{
        cout<<1;
    }
    int f1=0,f2=0;
    if(b[2]=='D' || b[2]=='F'){
        f1=1;
    }
    if(d[2]=='D' || d[2]=='F'){
        f2=1;
    }
    if(f1==f2){
        cout<<1;
    } else {
        cout<<0<<0;
        return 0;
    }
    if(d[2]-b[2]==1 || b[2]-d[2]==1 || f1==f2==1){
        cout<<1;
    } else cout<<0;
    return 0;
}
