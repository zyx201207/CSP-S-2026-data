#include <bits/stdc++.h>
using namespace std;
long long n,m,x,y;
string a,b;
char c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>a>>m>>b;
    x=(a[0]-'0')*10+(a[1]-'0');
    y=(b[0]-'0')*10+(b[1]-'0');
    c=a[2];
    d=b[2];
    if(n==m) cout<<"1";
    else cout<<"0";
    if(n==m&&x==y) cout<<"1";
    else cout<<"0";
    if(n==m&&x==y&&(((c=='A'||c=='B'||c=='C')&&(d=='A'||d=='B'||d=='C'))||((c=='D'||c=='F')&&(d=='D'||d=='F')))) cout<<"1";
    else cout<<"0";
    if(n==m&&x==y&&((c+1==d&&c+1!='D')||(c-1==d&&c-1!='C'))) cout<<"1";
    else cout<<"0";
    return 0;
}
