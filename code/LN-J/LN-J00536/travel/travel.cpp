#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,n1;
    string s,s1;
    cin>>n>>s>>n1>>s1;
    int m=(s[0]-'0')*10+(s[1]-'0'),m1=(s1[0]-'0')*10+(s1[1]-'0');
    char c=s[2],c1=s1[2];
    if(n==n1){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(m==m1){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if(((c>='A'&&c<='C')&&(c1>='A'&&c1<='C'))||((c>='D'&&c<='F')&&(c1>='D'&&c1<='F'))){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(abs(c-c1)==1){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
