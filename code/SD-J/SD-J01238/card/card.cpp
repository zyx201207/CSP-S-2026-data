#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int N=5e5+10,M=3e5+10;
int a[N];
bool b[M];
long long ans[M];
stack<long long> q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i;j<=n;j++)
		{
			if(j==1)
			{
				b[a[j]]=1;
				q.push(a[j]);
			}else
			{
				if(b[a[j]]==1)
				{
					while(q.top()!=a[j])
					{
						b[q.top()]=0;
						q.pop();
					}
				}else
				{
					b[a[j]]=1;
					q.push(a[j]);
				}
			}
		}
		while(!q.empty())
		{
			ans[q.top()]++;
			b[q.top()]=0;
			q.pop();
		}
	}
	for(long long i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
} 
