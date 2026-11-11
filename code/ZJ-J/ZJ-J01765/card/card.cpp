#include<bits/stdc++.h>
using namespace std;
stack<long long>q;
map<long long,long long>s,a;
long long n,m;
int b[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof b);
		for(int j=i;j<=n;j++)
		{
			if(!b[a[j]])
			{
				b[a[j]]=1;
				q.push(a[j]);
			}
			else
			{
				while(q.top()!=a[j])
				{
					q.pop();
				}
			}
		}
		while(!q.empty())
		{
			s[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<' ';
	return 0;
}
