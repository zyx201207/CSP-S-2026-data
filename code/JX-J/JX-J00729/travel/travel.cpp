#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string c,d;
    cin>>a;
    for(int i=1;i<=3;i++){
        cin>>c[i];
    }
    cin>>b;
    for(int i=1;i<=3;i++){
        cin>>d[i];
    }
    if(a==b){
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    if((c[1]-'0'+c[2]-'0')==(d[1]-'0'+d[2]-'0')){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    if((c[3]<='C'&&d[3]<='C')||(c[3]>='D'&&d[3]>='D')){
        cout<<"1";
    }
    else{
        cout<<"00";
        return 0;
    }
    if(c[3]-d[3]==1||c[3]-d[3]==-1){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    //qu xiao zhu shi.
    return 0;
}
