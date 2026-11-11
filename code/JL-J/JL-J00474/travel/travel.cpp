#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,s;
int a,b,c,d,e,f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    s=s1[2]+s2[2];
    a=(s1[0]-'0')*10+(s1[1]-'0');
    b=(s2[0]-'0')*10+(s2[1]-'0');
    c=max(int(s1[2]),int(s2[2]))-min(int(s1[2]),int(s2[2]));
    if(c1==c2){
        cout<<1;
        d=1;
    }else{
        cout<<0;
    }
    if(a==b&&d){
        cout<<1;
        e=1;
    }else{
        cout<<0;
    }
    if(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&d&&e){
            cout<<1;
            f=1;
    }else{
            cout<<0;
    }
    if(c&&((s!="DC"||s!="CD")||(s=="FD"||s=="DF"))&&d&&e&&f){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
