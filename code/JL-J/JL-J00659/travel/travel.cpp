#include<bits/stdc++.h>
using namespace std;
int c1,s1;
char c2,s2;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1=s1)cout<<1;
    else cout<<0;
    char c=c2-32,s=s2-32;
    int a=0;
    if(c<s){
        a=c;
        c=s;
        s=a;
    }
    if(c-s<=4)cout<<1;
    else cout<<0;
    if(c-s<=2)cout<<1;
    else cout<<0;
    if(c-s<=1)cout<<1;
    else cout<<0;
    return 0;
}
