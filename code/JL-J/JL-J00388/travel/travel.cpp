#include<bits/stdc++.h>
using namespace std;
string c,s,ca,sa;
bool n,m,a,b,d,e,f,g;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>ca>>sa;
    n=(c==ca);
    m=((s[0]+s[1]==sa[0]+sa[1])&&n);
    a=(s[2]=='A'||s[2]=='B'||s[2]=='C');
    b=((sa[2]=='A'|sa[2]=='B'||sa[2]=='C')&&a);
    d=(s[2]=='D'||s[2]=='F');
    e=((sa[2]=='D'||sa[2]=='F')&&d);
    f=(abs(s[2]-sa[2])==1);
    g=(s[2]=='D'&&sa[2]=='F')||(sa[2]=='D'&&s[2]=='F');
    if(n){
        cout<<1;
    }else{
        cout<<0;
    }
    if(m){
        cout<<1;
    }else{
        cout<<0;
    }
    if(m&&(b||e)){
        cout<<1;
    }else{
        cout<<0;
    }
    if(m&&(b||e)&&(f||g)){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
