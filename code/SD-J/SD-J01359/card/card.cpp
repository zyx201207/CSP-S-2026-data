#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt[500005],ans[500005];
vector<int>p;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int l=1;l<=n;l++)
	{
		memset(cnt,0,sizeof(cnt));
		p.clear();
		for(int i=l;i<=n;i++)
		{
			memset(cnt,0,sizeof(cnt));
			for(int j=0;j<p.size();j++)
			{
				cnt[p[j]]=1;
			}
			int k=a[i];
			if(cnt[k])
			{
				int o=0;
				for(int j=0;j<p.size();j++)
				{
					if(p[j]==k)
					{
						o=j;
						break;
					}
				}
				for(int j=o;j<p.size();j++)
				{
					p[j]=0;
				}
				p[o]=k;
				
			}
			else{
				cnt[k]=1;
				p.push_back(k);
			}
			
			
		}
		memset(cnt,0,sizeof(cnt));
		for(int j=0;j<p.size();j++)
		{
			cnt[p[j]]=1;
		}
		for(int j=1;j<=m;j++)
		{
			if(cnt[j])
			{
				ans[j]++;
			}
		}
		
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
