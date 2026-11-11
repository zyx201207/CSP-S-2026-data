#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=200050;
int n,a[MAXN],l=1,r=0,x=1,y,minn=0;
char c[MAXN];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	y=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
		r+=a[i];
	}
	while(x<y)
	{
		if(a[x]>a[y])
		{
			if(c[x]!=c[y])
			{
				minn+=a[y];
			}
			a[x]-=a[y];
			y--;
		}
		else if(a[x]<a[y])
		{
			if(c[x]!=c[y])
			{
				minn+=a[x];
			}
			a[y]-=a[x];
			x++;
		}
		else
		{
			if(c[x]!=c[y])
			{
				minn+=a[x];
			}
			y--;
			x++;
		}
	}
	cout<<minn;
	return 0;
}
