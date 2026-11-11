#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int ans=1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=c[i]) ans=0;
	}
	cout<<ans;
	for(int i=0;i<b.size()-1;i++)
	{
		if(b[i]!=d[i]) ans=0;
	}
	cout<<ans;
	if(b[2]=='C'&&d[2]!='B'&&d[2]!='A'||b[2]=='B'&&d[2]!='A'&&d[2]!='C'||b[2]=='A'&&d[2]!='B'&&d[2]!='C'||b[2]=='D'&&d[2]!='F'||b[2]=='F'&&d[2]!='D') ans=0;
	cout<<ans;
	if(ans==0) cout<<ans;
	else
	{
		ans=0;
		if(abs(b[2]-d[2])==1) ans=1;
		cout<<ans;
	}
	return 0;
}