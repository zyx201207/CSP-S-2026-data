#include <bits/stdc++.h>
#define ll long long
#define isok cout << "ok" << endl
#define DB(s,a) cout << s << ":" << a << endl
using namespace std ;
const ll MAXN = 100005 ;
string c1 , c2 , s1 , s2 ;
char h1 , h2 ;
bool q1 , q2 , q3 , q4 ;
int main(){
    freopen("travel.in","r",stdin) ;
    freopen("travel.out","w",stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    cin >> c1 >> s1 >> c2 >> s2 ;
    h1 = s1[2] ;
    h2 = s2[2] ;
    q1 = (c1==c2) ;
    q2 = (q1 && (s1[0]==s2[0] && s1[1]==s2[1])) ;
    q3 = (q2 && ((h1>='A' && h1<='C' && h2>='A' && h2<='C') || (h1>='E' && h1<='F' && h2>='E' && h2<='F'))) ;
    q4 = (q3 && !(h1=='A' && h2=='C') && !(h1=='C' && h2=='A')) ;
    cout << q1 << q2 << q3 << q4 ;
    return 0 ;
}
//freopen
//迷惑行为诱捕器
