#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m;
int a[N],cnt[40];
vector<int>g[40];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(int x=a[i],j=0;x;x>>=1,j++)
			if(x&1)cnt[j]++;
	}
	int chose=-1;
	for(int i=35;i>=0;i--)
		if(cnt[i]>=m)
		{
			chose=i;
			break;
		}
	if(chose==-1)
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
		if((a[i]>>chose)&1)g[chose].push_back(i);
	int ans=(1<<chose);
	for(int i=chose-1;i>=0;i--)
	{
		for(int j:g[i+1])
			if((a[j]>>i)&1)
				g[i].push_back(j);
		if(g[i].size()<m)
		{
			for(int j:g[i+1])
				if(((a[j]>>i)&1)==0)
					g[i].push_back(j);
		}
		else ans|=(1<<i);
	}
	printf("%lld",ans);
	return 0;
}
