#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	bool ke=true;
	if((a[0]!=c[0]||a[1]!=c[1])&&ke)
	{
		cout<<"0000";
		ke=false;
	}
	if((b[0]!=d[0]||b[1]!=d[1])&&ke)
	{
		cout<<"1000";
		ke=false;
	}
	char s=b[2];
	char x=d[2];
	if(!((s>='A'&&s<='C'&&x>='A'&&x<='C')||(s>='D'&&s<='F'&&x>='D'&&x<='F'))&&ke)
	{
		cout<<"1100";
		ke=false;
	}
	if(abs((int)(s-x))!=1&&ke)
	{
		cout<<"1110";
		ke=false;
	} 
	if(ke) cout<<"1111";
	return 0;
}
