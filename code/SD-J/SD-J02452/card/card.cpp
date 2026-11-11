#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
long long n,m,a[N],to[N],ans[N];
deque<long long>q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	long long t=1;
	while(t<=n)
	{
		if(t==n)
		{
			ans[a[n]]++;
			break;
		}
		memset(to,0,sizeof to);
		for(long long i=t;i<=n;i++)
		{
			if(to[a[i]]==0)
			{
				q.push_back(a[i]);
				to[a[i]]=1;
			}
			else
			{
				while(q.size()&&q.back()!=a[i])
				{
					to[q.back()]=0;
					q.pop_back();
				}
			}
		}
		while(q.size())
		{
			ans[q.front()]++;
			q.pop_front();
		}
		t++;
	}
	for(long long i=1;i<=m;i++)
	{
		cout<<ans[i];
		if(i!=m)
			cout<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
