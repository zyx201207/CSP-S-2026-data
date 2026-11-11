#include<bits/stdc++.h>
#define ll long long
#define db double
const int N=1e6+10,inf=0x3f3f3f3f;
using namespace std;
ll n,m,a[N],vis[N],ans[N],cnt1,flag1,sum[N],b[N];
stack<ll>q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=a[i-1])
			cnt1++;
		if(a[i]<a[i-1])
			flag1=0;
	}
	if(flag1&&n>5000)
	{
		for(int i=1;i<=n;i++)
			if(a[i]!=a[i-1])
				sum[a[i]]=n-1;
		sum[m]=n;
		for(int i=1;i<=m;i++)
			cout<<sum[i]<<" ";
		return 0;
	}
	if(cnt1<=5000&&n>5000)
	{
		int t=0;
		for(int i=1;i<=n+1;i++)
			if(a[i]!=a[i-1])
				b[++t]=a[i-1];
		for(int i=1;i<=t;i++)
			a[i]=b[i];
		n=t;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			vis[j]=0;
		for(int j=i;j<=n;j++)
		{
			
			if(vis[a[j]])
			{
				while(q.size()&&q.top()!=a[j])
					vis[q.top()]--,q.pop();
				vis[a[j]]--;
			}
			else
				q.push(a[j]);
			vis[a[j]]++;
		}
		int cnt=0;
		while(!q.empty())
		{
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
/*
4 3
1 2 1 3
*/
