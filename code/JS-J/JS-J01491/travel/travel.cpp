#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
    if(a!=c)
    {
        cout<<"0000";
        return 0;
    }
    cout<<'1';
    if(b[0]!=d[0]||b[1]!=d[1])
    {
        cout<<"000";
        return 0;
    }
    cout<<'1';
    int f1=0,f2=0;
    if(b[2]=='A'||b[2]=='B'||b[2]=='C') f1=1;
    else f1=2;
    if(d[2]=='A'||d[2]=='B'||d[2]=='C') f2=1;
    else f2=2;
    if(f1!=f2)
    {
        cout<<"00";
        return 0;
    }
    cout<<'1';
    if((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A')) cout<<'0';
    else cout<<'1';
	return 0;
}
