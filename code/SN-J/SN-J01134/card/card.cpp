#include<bits./stdc++.h>
using namespace std;
long long a[500005];
long long sh[500005];
long long cnt[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		stack<long long> s;
		for(int q=1;q<=m;q++)
	{
		cnt[m]=0;
	}
		for(int j=i;j<=n;j++)
	{
		cnt[a[j]]++;
		if(cnt[a[j]]==2)
		{
			while(!s.empty())
			{
				if(s.top()==a[j])
				{
					s.pop();
					break;
				}
				else
				{
					s.pop();
				}
			}
		}
		s.push(a[j]);
	}
	while(!s.empty())
	{
		
		sh[s.top()]++;
		s.pop();
	}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sh[i]<<' ';
	}
	return 0;
 }
