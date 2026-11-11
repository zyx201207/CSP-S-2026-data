#include<bits/stdc++.h>
using namespace std;
long long n,x,y,ans;
struct{
	long long a;
	char c;
}f[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>f[i].a>>f[i].c;
	}
	x=1;y=n;
	while(x<=y)
	{
		if(f[x].c!=f[y].c)
		{
			ans+=min(f[x].a,f[y].a);
		}
		if(f[x].a>f[y].a)
		{
			f[x].a-=f[y].a;
			y--;
		}
		else if(f[x].a<f[y].a)
		{
			f[y].a-=f[x].a;
			x++;
		}
		else
		{
			y--;
			x++;
		}
	}
	cout<<ans;
	return 0;
}