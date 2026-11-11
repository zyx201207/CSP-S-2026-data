#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string p1=s1.substr(0,2),p2=s2.substr(0,2);
    char b1=s1[2],b2=s2[2];
    cout<<(c1==c2);
    cout<<(c1==c2&&p1==p2);
    bool flag=(c1==c2&&p1==p2&&(b1<='C'&&b2<='C'||b1>='D'&&b2>='D'));
    cout<<flag;
    cout<<(flag&&abs(b1-b2)==1);
    return 0;
}
