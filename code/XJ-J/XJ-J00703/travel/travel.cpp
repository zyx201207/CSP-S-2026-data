#include<bits/stdc++.h>
using namespace std;
int i,f=1;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	for(i=0;i<=1;i++)
	if(a[i]!=b[i])
	f=0;
	if(f==1)
	{
		f=1;
		for(i=0;i<=1;i++)
		if(c[i]!=d[i])
		f=0;
		if(f==1)
		{
			if((c[2]<='C'&&d[2]<='C')||c[2]>='D'&&d[2]>='D')
			{
				if(c[2]-d[2]<=1)
				cout<<"1111";
				else
				cout<<"1110";
			}
			else
			cout<<"1100";
		}
		else
		cout<<"1000";
	}
	else
	cout<<"0000";
	return 0;
}