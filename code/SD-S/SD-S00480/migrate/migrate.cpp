#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000009],cc,ans;
bool de()
{
	int j=a[2]-a[1];
	for(int i=2;i<n;i++)
		if(a[i+1]-a[i]!=j)
			return false;
	cc=j;
	return true;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>c>>t;
	while(t--)
	{
		ans=0;
		cin >>n>>d;
		for(int i=1;i<=n;i++)
			cin >>a[i];
		if(de())
		{
			d/=cc;
			ans=n-d-1;
		}
		cout <<ans<<endl;
	}
	return 0;
}

