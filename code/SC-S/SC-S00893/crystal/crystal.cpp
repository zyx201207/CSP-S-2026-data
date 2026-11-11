#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5+10;

long long N,M,K;

long long a[MAXN],val[MAXN];

long long cnt[MAXN],pre[MAXN],sum[MAXN];

inline int Find(int x,int y,int v)
{
	int l=x-1,r=y+1,mid;
	
	while(l+1!=r)
	{
		mid=(l+r)/2;
		
		if(pre[y]-pre[mid-1]>v)
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	
	return r;
}

inline bool Check(int mid)
{
	for(int i=1,d,res;i<=K;i++)
	{
		if(cnt[i]>=mid)
		{
			return true;
		}
		
		d=mid-cnt[i];
		
		if(pre[i-1]<d)
		{
			continue;
		}
		
		res=Find(1,i-1,d);
		
		long long need=(pre[i-1]-pre[res-1])*val[i]-(sum[i-1]-sum[res-1])+(d-(pre[i-1]-pre[res-1]))*(val[i]-val[res-1]);
		
		if(need<=M)
		{
			return true;
		}
	}
	
	return false;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		cin>>a[i];
	}
	
	{
		unordered_map<long long,int> rk;
		
		for(int i=1;i<=N;i++)
		{
			val[i]=a[i];
		}
		
		sort(val+1,val+N+1);
		K=unique(val+1,val+N+1)-val-1;
		
		for(int i=1;i<=K;i++)
		{
			rk[val[i]]=i;
		}
		
		for(int i=1;i<=N;i++)
		{
			a[i]=rk[a[i]];
		}
	}
	
	for(int i=1;i<=N;i++)
	{
		cnt[a[i]]++;
	}
	
	for(int i=1;i<=K;i++)
	{
		pre[i]=pre[i-1]+cnt[i];
		sum[i]=sum[i-1]+cnt[i]*val[i];
	}
	
	long long l=0,r=N+1,mid;
	
	while(l+1!=r)
	{
		mid=(l+r)/2;
		
		if(Check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	
	cout<<l<<'\n';
	
	return 0;
}