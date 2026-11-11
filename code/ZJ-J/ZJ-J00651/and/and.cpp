#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long cnt[31],a[N];
long long n,m;
typedef  pair<long long,int> PII;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	bool flag=0,flag1=0;
	cin>>n>>m;
	priority_queue<PII> q_max;
	queue<PII> q;
	for(int i=1;i<=n;i++)
	{
		int k=0,w;
		cin>>a[i];
		w=a[i];
		while(w)
		{
			cnt[++k]+=w%2;
			w/=2;
		}
		if(a[i]>4)
		{
			flag=1;
		}
		w=a[i]+1;
		while(w)
		{
			if(w%2==1)
			{
				flag1=1;
			}
			w/=2;
		}
		q_max.push({a[i],i});
	}
	if(flag==0)
	{
		int sum[5];
		for(int i=1;i<=n;i++)
		{
			sum[a[i]]++;
		}
		if(sum[4]>=m)
		{
			cout<<4;
			return 0;
		}
		if(sum[3]>=m)
		{
			cout<<3;
			return 0;
		}
		if(sum[3]+sum[2]>=m)
		{
			cout<<2;
			return 0;
		}
		if(sum[3]+sum[1]>=m)
		{
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	if(flag1==0)
	{
		sort(a+1,a+n+1);
		int ed=a[n];
		for(int i=n;i>=n-m+1;i++)
		{
			ed&=a[i];
		}
		cout<<ed;
		return 0;
	}
	for(int i=30;i>=1;i--)
	{
		if(cnt[i]==m)
		{
			int sum=a[q_max.top().second];
			for(int i=1;i<=m;i++)
			{
				sum&=a[q_max.top().second];
				q_max.pop();
			}
			cout<<sum;
			return 0;
		}
		else if(cnt[i]>m)
		{
			while(cnt[i]--)
			{
				q.push(q_max.top());
				q_max.pop();
			}
			while(q_max.size())
			{
				int w=q_max.top().first,k=0;
				while(w)
				{
					cnt[++k]-=w%2;
					w/=2;
				}
				q_max.pop();
			}
			while(q.size())
			{
				q_max.push({q.front().first%(long long)pow(2,i),q.front().second});
				q.pop();
			}
		}
		else
		{
			while(q_max.size())
			{
				q.push(q_max.top());
				q_max.pop();
			}
			while(q.size())
			{
				q_max.push({q.front().first%(long long)pow(2,i),q.front().second});
				q.pop();
			}
		}
	}
	int sum=a[q_max.top().second];
	while(q_max.size())
	{
		sum&=a[q_max.top().second];
		q_max.pop();
	}
	cout<<sum;
	return 0;
}
