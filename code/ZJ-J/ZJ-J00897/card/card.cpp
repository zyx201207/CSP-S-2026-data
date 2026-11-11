#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[500005];
vector<long long>v;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	cin>>n>>m;
	for(long long i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;++i)
	{
		v.clear();
		for(long long j=i;j<=n;++j)
		{
			long long tag=-1;
			for(long long k=v.size()-1;k>=0;--k)
			{
				if(v[k]==a[j])
				{
					tag=k;
					break;
				}
			}
			if(tag!=-1)
			{
				v.resize(tag);
			}
			v.push_back(a[j]);
		}
		for(long long i=0;i<v.size();++i)
		{
			++ans[v[i]];
		}
	}
	for(long long i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}