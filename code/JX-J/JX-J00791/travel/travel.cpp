#include<bits/stdc++.h>
using namespace std;
bool s(string a,string b)
{
    if(a[2]=='A'||a[2]=='B'||a[2]=='C')
    {
        if(b[2]=='A'||b[2]=='B'||b[2]=='C') return 1;
        else return 0;
    }
    else
    {
        if(a[2]=='D'&&b[2]=='E'||a[2]=='E'&&b[2]=='D') return 1;
        else return 0;
    }
}
string a,a1,b,b1;
bool j,j2,j3,j4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a>>b1>>b;
    if(a1==b1)
    {
        cout<<1;
        j=1;
    }
    else cout<<0;
    if(a[0]==b[0]&&a[1]==b[1]&&j)
    {
        cout<<1;
        j2=1;
    }
    else cout<<0;
    if(s(a,b)&&j&&j2)
    {
        cout<<1;
        j3=1;
    }
    else cout<<0;
    if(char(a[2]-1)==char(b[2])||char(a[2]+1)==char(b[2])&&j&&j2&&j3) cout<<1;
    else cout<<0;
    return 0;
}
