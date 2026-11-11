#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
int c1,c2;
string s1,s2;
cin>>c1>>s1>>c2>>s2;
if(c1==c2){
    cout<<1;
    int pai1,pai2;
    pai1=s1[0]*10+s1[1];
    pai2=s2[0]*10+s2[1];
    if(pai1==pai2){
        cout<<1;
        char zuo1,zuo2;
        zuo1=s1[2];
        zuo2=s2[2];
        int a=zuo1,b=zuo2;
        if((a==67&&b==68)||(a==68&&b==67)){
            cout<<"00";
            return 0;
        }
        if(a>=65&&a<=67&&b>=65&&b<=67){
            if(a-b==1||a-b==-1){
                cout<<"11";
                return 0;
            }
            else{
                cout<<"10";
                return 0;
            }
        }
        else{
            if(a>=68&&a<=70&&b>=68&&b<=70){
                cout<<"11";
                return 0;
            }
            else{
                cout<<"00";
                return 0;
            }
        }

    }
    else{
        cout<<"000";
        return 0;
    }
}
else{
    cout<<"0000";
    return 0;
}
return 0;
}
