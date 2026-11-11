#include <bits/stdc++.h>
using namespace std;
string x1,yy,x2,ye;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x1>>x2>>yy>>ye;
    if(x1==yy){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(x2[0]==ye[0]&&x2[1]==ye[1]){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    int a=x2[2]-'A',b=ye[2]-'A';
    if(!(a<=2^b<=2)){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }
    if((a==0&&b==2)||(a==2&&b==0)){
        cout<<0;
    }
    else cout<<1;
}


