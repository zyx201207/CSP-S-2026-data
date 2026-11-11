#include<bits/stdc++.h>
using namespace std;
int c,t,n,f[2000010],cnt,sum;
long long d,a[2000010],ans;
void dfs(int s,int t,int c)
{
	cout<<s<<'\n';
	if(c==cnt&&s==t)
	{
		++sum;
		return;
	}
	for(int i=min(f[s],t);i>=s+1;--i)
		dfs(i,t,c+1);
}
int main()
{
	scanf("%d%d",&c,&t);
	while(t--)
	{
		ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;++i)
			scanf("%lld",&a[i]);
		int l;
		for(l=1;l<=n;++l)
			if((a[l]-a[1])<=d&&(a[l+1]-a[1])>d)
			{
				f[1]=l;
				break;
			}
		for(int i=2;i<=n;++i)
		{
			while(a[l+1]-a[i]<=d&&l!=n)
				++l;
			f[i]=l;
		}
		for(int i=1;i<n-2;++i)
			for(int j=i+3;j<=n;++j)
			{
				int x=i;sum=cnt=0;
				while(x<j)
				{
					if(f[x]==x)
					{
						cnt=-1;
						continue;
					}
					x=f[x];
					++cnt;
				}
				if(cnt!=-1)
				{
					cout<<i<<' '<<j<<' '<<cnt<<'\n';
					dfs(i,j,0);
				}
				if(sum==2)
					++ans;
			}
		printf("%lld\n",ans);
	}
	return 0;
}
