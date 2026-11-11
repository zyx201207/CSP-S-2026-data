#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5;
int a1,b1;
string a2,b2;
int iftrain(int x,int y) { if(x==y) return 1;   return 0; }
int ifline(string x,string y){ if(x[0]==y[0] && x[1]==y[1]) return 1;   return 0; }
int ifside(string x,string y){
    if((x[2]=='D' || x[2]=='F') && (y[2]=='D' || y[2]=='F')) return 1;
    if((x[2]=='A' || x[2]=='B' || x[2]=='C') && (y[2]=='A' || y[2]=='B' || y[2]=='C')) return 1;
    return 0;
}
int ifbeside(string x,string y){
    if(x[2]=='A' && y[2]=='B') return 1;
    if(x[2]=='B' && (y[2]=='A' || y[2]=='C')) return 1;
    if(x[2]=='C' && y[2]=='B') return 1;
    if(x[2]=='D' && y[2]=='F') return 1;
    if(x[2]=='F' && y[2]=='D') return 1;
    return 0;
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(iftrain(a1,b1)==0){ cout<<"0000"; return 0; }
    else cout<<1;

    if(ifline(a2,b2)==0){ cout<<"000"; return 0; }
    else cout<<1;

    if(ifside(a2,b2)==0){ cout<<"00"; return 0; }
    else cout<<1;

    if(ifbeside(a2,b2)==0){ cout<<"0"; return 0; }
    else cout<<1;

    return 0;
}
