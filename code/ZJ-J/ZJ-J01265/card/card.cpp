#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum[300005],cnt[300005];
bool v[500005],f=0;
stack<int> s;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>a[i-1])
			f=1;
		
	}
	if(f==0)
	{
		for(int i=1;i<=n;i++)
		{
			cnt[a[i]]++;
		}
		for(int i=2;i<=m;i++)
		{
			cnt[i]+=cnt[i-1];
		}
		for(int i=1;i<=m;i++)
		{
			cout<<cnt[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++)
		{
			if(v[a[j]]==0)
			{
				v[a[j]]=1;
				s.push(a[j]);
			}
			else
			{
				while(s.top()!=a[j])
				{
					v[s.top()]=0;
					s.pop();
				}
			}
		}
		while(s.size())
		{
//			cout<<s.top()<<" ";
			sum[s.top()]++;
			s.pop();
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
}