#include<bits/stdc++.h>
using namespace std;
int a[50005];
int sum[30005];
int cnt[30005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(cnt,0,sizeof(cnt));
		stack<int> s;
		for(int j=i;j<=n;j++)
		{
			if(cnt[a[j]]==0)
			{
				s.push(a[j]);
				cnt[a[j]]+=1;
			}
			else
			{
				while(!s.empty())
				{
					int x=s.top();
					s.pop();
					if(x==a[j])
					{
						s.push(x);
						break;
					}
					cnt[x]-=1;
				}
			}
		}
		int len=s.size();
		for(int j=1;j<=len;j++)
		{
			int x=s.top();
			s.pop();
			sum[x]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
}
