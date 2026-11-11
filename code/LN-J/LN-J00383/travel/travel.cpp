#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
struct node{
    int c,s1;
    string s;
}r,x;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> r.c >> r.s >> x.c >> x.s;
    r.s1=(r.s[0]-'0')*10+(r.s[1]-'0');
    x.s1=(x.s[0]-'0')*10+(x.s[1]-'0');
    if(r.c==x.c){
        a=1;
    }
    if(a && r.s1==x.s1){
        b=1;
    }
    if(b && (r.s[2]>='A' && r.s[2]<='C' && x.s[2]>='A' && x.s[2]<='C') || (r.s[2]>='D' && r.s[2]<='F' && x.s[2]>='D' && x.s[2]<='F')){
        c=1;
    }
    if(c && abs(r.s[2]-x.s[2])==1 || (r.s[2]=='D' && r.s[2]=='F')|| (x.s[2]=='F' && x.s[2]=='D')){
        d=1;
    }
    cout << a << b << c << d;
    return 0;
}
