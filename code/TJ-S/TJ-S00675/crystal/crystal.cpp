#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a,b,n[500000],o,cmt=1;
	cin>>a>>b;
	cin>>n[500000];
	for(int i=1;i<=a;i++)
	{
		o=n[i]-n[i-1];
		if(o>b)
		{
			continue;
		}
		else if(o==b)
		{
			cmt++;
			cout<<cmt;
			return 0;
		}
		else
		{
			cmt++;
			b-=o;
		}
		if(cmt==0)
		{
			cout<<0;
			return 0;
		}
	}
	cout<<cmt;
	return 0;
}
