#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r","stdin");
    freopen("travel.out","w","stdout");
    int n;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
    cout<<"1";
    }else{
    cout<<"0000";
    return 0;
    }
    char a=c2/10,b=s2/10;
    if(a==b) cout<<1;
    else{
         cout<<0000;
         return 0;
    }
    a=s1%10,b=s2%10;
    if(a='c'&&b='0'||a='0',b='c')
}
