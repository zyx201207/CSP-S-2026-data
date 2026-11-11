#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N=1e5+2 ;
string s1,s2,s3,s4 ;
bool f1=0,f2=0,f3=0,f4=0 ;
int main(){
    freopen("travel.in","r",stdin) ;
    freopen("travel.out","w",stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(0);cout.tie(0);
    cin >> s1 >> s2 >> s3 >> s4 ;
    char se1=s2[2],se2=s4[2] ;
    if(s1==s3) f1=1 ;
    if(s2[0]==s4[0]&&s2[1]==s4[1]) f2=1 ;
    if((se1>='A'&&se1<='C'&&se2>='A'&&se2<='C')||(se1>='D'&&se1<='F'&&se2>='D'&&se2<='F')) f3=1 ;
    if((se1=='D'&&se2=='F')||(se1=='F'&&se2=='D')) f4=1 ;
    if((se1=='A'&&se2=='B')||(se1=='B'&&se2=='A')) f4=1 ;
    if((se1=='B'&&se2=='C')||(se1=='C'&&se2=='B')) f4=1 ;
    if(f1) cout << 1 ;
    else cout << 0 ;
    if(f1&&f2) cout << 1 ;
    else cout << 0 ;
    if(f1&&f2&&f3) cout << 1 ;
    else cout << 0 ;
    if(f1&&f2&&f3&&f4) cout << 1 ;
    else cout << 0 ;
    return 0 ;
}
