#include  <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c,e[10],f[10];
    char b[10],d[10];
    cin>>a>>b[10]>>c>>d[10];
    for(int i==0;i<10;i++){
        e[i]=b[i];
        f[i]=d[i];
    }
    if(a==c){
        cout<<"1";
    }
    else{
    cout<<"0";
    }
    if(e[0]==f[0] and e[1]==f[1]){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if(e[2]==f[2] and e[3]==f[3]+1){
    cout<<"1";
    }
    else if(e[2]==f[2] and e[3]==f[3]-1){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
