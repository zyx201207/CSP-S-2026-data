#include<bits/stdc++.h>
using namespace std;
int n1,n2,m1,m2,f1,f2;
char ch1,ch2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n1>>s1>>n2>>s2;
    if(n1==n2)cout<<1;
    else cout<<0;
    m1=(s1[0]-'0')*10+s1[1]-'0';
    m2=(s2[0]-'0')*10+s2[1]-'0';
    ch1=s1[2];
    ch2=s2[2];
    if(ch1>='D')f1=1;
    if(ch2>='D')f2=1;
    if(n1==n2&&m1==m2)cout<<1;
    else cout<<0;
    if(n1==n2&&f1==f2&&m1==m2)cout<<1;
    else cout<<0;
    if(f1==f2&&n1==n2&&m1==m2){
        if(ch1+1==ch2||ch2+1==ch1)cout<<1;
        else cout<<0;
    }
    else cout<<0;
    return 0;
}
