#include <bits/stdc++.h>
using namespace std;
string c1,a,c2,b,s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>a>>c2>>b;
    s1=a[0]+a[1];
    s2=b[0]+b[1];
    if(c1==c2)
    {
		cout<<1;
	}else cout<<0;
	bool l=0;
    if(s1==s2&&c1==c2)
    {
		cout<<1;
		l=1;
    }else cout<<0;
    bool l2=0;
    if(l==1&&((a[2]>='A'&&a[2]<='C'&&b[2]>='A'&&b[2]<='C')||((a[2]=='D'||a[2]=='F')&&(b[2]=='D'||b[2]=='F'))))
    {cout<<1;l2=1;}
    else cout<<0;
    if(l2==1&&(abs(a[2]-b[2])==1||(a[2]=='D'&&b[2]=='F')||(a[2]=='F'&&b[2]=='D')))
        cout<<1;
    else cout<<0;
    return 0;
}
