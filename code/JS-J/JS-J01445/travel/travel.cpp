#include<bits/stdc++.h>
#define int long long
using namespace std;
int xa,xb,a,b,c,d;
string sa,sb;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>xa>>sa;
    cin>>xb>>sb;
    a=(xa==xb);
    b=a&&sa[0]==sb[0]&&sa[1]==sb[1];
    c=b&&(sa[2]<='C'&&sb[2]<='C'||sa[2]>='D'&&sb[2]>='D');
    d=c&&!(sa[2]=='A'&&sb[2]=='C'||sa[2]=='c'&&sb[2]=='A');
    cout<<a<<b<<c<<d;
    return 0;
}/*













inclusteam
dcciyiyz
tdchuidiervsxt
2026/10/31 8:30:00
*/
