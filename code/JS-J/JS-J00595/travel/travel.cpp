#include<bits/stdc++.h>
using namespace std;
int a;
string b;
int c;
string d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;;
    cout<<(a==c)?1:0;
    cout<<(a==c&&b[0]==d[0]&&b[1]==d[1])?1:0;
    cout<<(a==c&&b[0]==d[0]&&b[1]==d[1]&&((b[2]<'D'&&d[2]<'D')||(b[2]>'C'&&d[2]>'C')))?1:0;
    cout<<(a==c&&b[0]==d[0]&&b[1]==d[1]&&((b[2]<'D'&&d[2]<'D')||(b[2]>'C'&&d[2]>'C'))&&abs(b[2]-d[2])==1)?1:0;
    cout<<endl;
    return 0;
}