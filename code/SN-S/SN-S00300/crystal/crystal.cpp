#include<bits/stdc++.h>

using namespace std;
long long n,m;
long long a[500005],cnt[500005],sam[500005];
long long ans[500005];

void find(int u)
{
	int tem=0;
	int mm=m;
	for(int i=u;i<n;i++)
	{
		tem+=a[i+1]-a[i];
		if(tem>mm)
		{
			break ;
		}
		else
		{
			mm=mm-tem;
			a[i]=a[i+1];
			ans[u]++;
		}
	}
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int sm=0;
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])
		{
			if(sm!=0&&a[i]==sam[sm])
			{
				cnt[sm]++;
			}
			else
			{
				sm++;
				sam[sm]=a[i];
				cnt[sm]++;
			}
		}
	}
	if(m==0)
	{
		long long ans_=1;
		for(int i=1;i<=sm;i++)
		{
			ans_=max(ans_,cnt[sm]);
		}
		cout<<ans_;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			ans[i]=1;
			find(i);
		}
		long long tem=1;
		for(int i=1;i<=n;i++)
		{
			tem=max(tem,ans[i]);
	    }
	    cout<<tem;
	}
	return 0;
}
