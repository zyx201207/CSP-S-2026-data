#include<bits/stdc++.h>
using namespace std;
long long a,c;
string b,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%2d",&a);
    cin>>b;
    scanf("%2d",&c);
    cin>>d;
    if(a!=c){
        cout<<"0000";
        return 0;
    }
    cout<<"1";
    if(b[0]==d[0]&&b[1]==d[1]){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    if((b[2]>='D'&&d[2]>='D')||(b[2]<='C'&&d[2]<='C')){
        cout<<"1";
    }
    else{
        cout<<"00";
        return 0;
    }
    if((b[2]==char(d[2]+1))||(d[2]==char(b[2]+1))){
        cout<<"1";
        return 0;
    }
    cout<<"0";
    return 0;
}
