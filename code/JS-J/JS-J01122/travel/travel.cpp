#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        string x=s1.substr(0,2),y=s2.substr(0,2);
        if(x==y){
            cout<<1;
            int a=(s1[2]-'A')+1,b=(s2[2]-'A')+1;
            if(a==6) a=5;
            if(b==6) b=5;
            bool flag1=(a<=3),flag2=(b<=3);
            if(flag1==flag2){
                cout<<1;
                if(abs(a-b)==1) cout<<1;
                else {cout<<0;return 0;}
            }
            else{cout<<"00";return 0;}
        }
        else {cout<<"000";return 0;}
    }
    else{cout<<"0000";return 0;}
    return 0;
}
