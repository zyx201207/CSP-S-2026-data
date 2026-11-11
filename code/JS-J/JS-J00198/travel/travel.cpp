#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d;
set<char>A,B;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(1);
    cin.tie(0),cout.tie(0);
    A.insert('A'),A.insert('B'),A.insert('C');
    B.insert('D'),B.insert('F');
    cin>>a>>b>>c>>d;
    if(a==c)cout<<1;
    else cout<<0;
    if(a==c&&b[0]==d[0]&&b[1]==d[1])cout<<1;
    else cout<<0;
    if(a==c&&b[0]==d[0]&&b[1]==d[1]&&!(A.count(b[2])&&B.count(d[2]))&&!(B.count(b[2])&&A.count(d[2])))cout<<1;
    else cout<<0;
    if(a==c&&b[0]==d[0]&&b[1]==d[1]&&!(A.count(b[2])&&B.count(d[2]))&&!(B.count(b[2])&&A.count(d[2]))&&(abs(b[2]-d[2])==1||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'))cout<<1;
    else cout<<0;
    return 0;
}
