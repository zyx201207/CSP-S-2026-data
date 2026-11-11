#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f;
char x,y;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>x>>c>>d>>y;
    e=int(x)-64;
    f=int(y)-64;
    if(a!=c){
        cout<<"0000";
        return 0;
    }
    else if(b!=d){
        cout<<"1000";
        return 0;
    }
    else if((e>3&&f<=3)||(e<=3&&f>3)){
        cout<<"1100";
        return 0;
    }
    else if(abs(e-f)!=1){
        cout<<"1110";
        return 0;
    }
    else cout<<"1111";
    return 0;
}
