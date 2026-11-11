#include<bits/stdc++.h>
using namespace std;
int a[200005],n;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int x=1,y=n;
	long long ans=0;
	while(x<y)
	{
		if(c[x]==c[y]&&a[x]==a[y])
		{
			x++;
			y--;
		}
		else
		{
			int z=min(a[x],a[y]);
			if(c[x]!=c[y])
				ans+=z;
			a[x]-=z;
			a[y]-=z;
			x+=(a[x]==0);
			y-=(a[y]==0);
		}
	}
	cout<<ans;
	return 0;
}
