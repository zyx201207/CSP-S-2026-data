#include<bits/stdc++.h>
using namespace std;
string c_1,s_1,c_2,s_2;
bool a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c_1>>s_1>>c_2>>s_2;
    if(c_1==c_2){
        a=true;
    }else{
        a=false;
        b=false;
        c=false;
        d=false;
        cout<<a<<b<<c<<d;
        return 0;
    }
    string tmp1,tmp2;
    tmp1+=s_1[0];
    tmp1+=s_1[1];
    tmp2+=s_2[0];
    tmp2+=s_2[1];
    if(tmp1==tmp2){
        b=true;
    }else{
        b=false;
        c=false;
        d=false;
        cout<<a<<b<<c<<d;
        return 0;
    }
    char tmp3=s_1[2];
    char tmp4=s_2[2];
    if(tmp3=='F'){
        tmp3='E';
    }if(tmp4=='F'){
        tmp4='E';
    }
    if(((tmp3>='A' and tmp3<='C') and (tmp4>='A' and tmp4<='C')) or ((tmp3>='D' and tmp3<='E') and (tmp4>='D' and tmp4<='E'))){
        c=true;
    }else{
        c=false;
        d=false;
        cout<<a<<b<<c<<d;
        return 0;
    }
    if(abs(tmp3-tmp4)==1){
        d=true;
    }else{
        d=false;
    }
    cout<<a<<b<<c<<d;
    return 0;
}
