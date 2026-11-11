#include<bits/stdc++.h>
using namespace std;

bool tyc(int a,int b)
{
    if(a=='A' && (b=='B' || b=='C')) return 1;
    else if(a=='B'&&(b=='A'||b=='C')) return 1;
    else if(a=='C'&&(b=='B'||b=='A')) return 1;
    else if(a=='D'&&b=='F') return 1;
    else if(a=='F'&&b=='D') return 1;
    return 0;
}
bool xl(int a,int b)
{
    if(a=='A'&&b=='B') return 1;
    if(a=='B'&&(b=='A'||b=='C')) return 1;
    if(a=='C'&&b=='B') return 1;
    if(a=='D'&&b=='F') return 1;
    if(a=='F'&&b=='D') return 1;
    return 0;
}


int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string ca,sa,cb,sb;
    cin >> ca>>sa>>cb>>sb;
    if(ca!=cb) cout << "0000";
    else if(sa[0]!=sb[0]||sa[1]!=sb[1])cout << "1000";
    else if(tyc(sa[2],sb[2])==0) cout << "1100";
    else if(xl(sa[2],sb[2])==0) cout << "1110";
    else cout << "1111";
    return 0;
}
