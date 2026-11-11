#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string c,d;
    cin>>a>>c>>b>>d;
    cout<<(a==b)<<(c[0]==d[0]&&c[1]==d[1]&&a==b)<<((c[2]>'C'&&d[2]>'C')||(c[2]<='C'&&d[2]<='C')&&c[0]==d[0]&&c[1]==d[1]&&a==b)<<((c[2]-d[2]==1||d[2]-c[2]==1)&&((c[2]>'C'&&d[2]>'C')||(c[2]<='C'&&d[2]<='C')&&c[0]==d[0]&&c[1]==d[1]&&a==b));
return 0;}
