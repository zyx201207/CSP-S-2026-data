#include<bits/stdc++.h>
using namespace std;

#define int long long
bitset<500005>bit[35],cnt;
int n,m,a[100005],ans;

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int maxn=0;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		maxn=max(a[i],maxn);
	}
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	else if(m==2)
	{
		maxn=0;
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}
	else if(m==n)
	{
		int tmp=a[1];
		for(int i=2; i<=n; i++)
		{
			tmp&=a[i];
		}
		cout<<tmp;
	}
	else if(m==n-1)
	{
		maxn=0;
		vector<int>a1,b1;
		a1.push_back(a1[1]);
		b1.push_back(b1[1]);
		for(int i=2; i<=n; i++)
		{
			a1.push_back(a1[i-2]&a[i]);
		}
		for(int i=n-1,j=0; i>=1; i--,j++)
		{
			b1.push_back(b1[j]&a[i]);
		}
		maxn=max(b1[1],a1[n-2]);
		for(int i=2; i<n; i++)
		{
			maxn=max(a1[i-2]&b1[i],maxn);
		}
		cout<<maxn;
	}
	else
	{
		int flag1=1;
		for(int i=1; i<=n; i++)
		{
			if(a[i]!=i-1)
			{
				flag1=0;
			}
		}
		if(flag1)
		{
			cout<<(a[n]&a[n-1]);
		}
		else
		{
			for(int i=0; i<=30; i++)
			{
				for(int j=1; j<=n; j++)
				{
					bit[i][j]=a[j]&(1<<i);
				}
			}
			for(int i=1; i<=n; i++)
			{
//		cout<<i<<'\n';
				cnt=0;
				int flag=0;
				for(int j=0; j<=30; j++)
				{
					if(a[i]&(1<<j))
					{
						if(flag==0)
						{
							cnt=bit[j];
							flag=1;
						}
						else
						{
							cnt&=bit[j];
						}
					}
//			cout<<cnt.count()<<' ';
				}
//		cout<<'\n';
				if(cnt.count()>=m)
				{
					ans=max(ans,a[i]);
				}
			}
			cout<<ans;
		}
	}
	return 0;
}
