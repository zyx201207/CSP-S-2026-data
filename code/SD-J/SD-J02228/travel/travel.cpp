#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int pd1,pd2,pd3,pd4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) pd1=1;
	if(b[0]==d[0]&&b[1]==d[1]&&pd1) pd2=1;
	if(pd1&&pd2&&((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'))) pd3=1;
	if(pd1&&pd2&&pd3&&(b[2]+1==d[2]||b[2]-1==d[2])) pd4=1;
	cout<<pd1<<pd2<<pd3<<pd4;
	return 0;
}
