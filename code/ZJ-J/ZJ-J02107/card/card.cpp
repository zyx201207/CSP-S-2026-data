#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5,maxm=3e5;
int n,m,a[maxn+5];
int cnt[maxm+5];
int ans[maxm+5];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(cnt,0,sizeof(cnt));
		stack<int>s;
		for(int j=i;j<=n;j++)
		{
			int p=a[j];
			if(cnt[p]==1)
			{
				while(s.top()!=p)
				{
					cnt[s.top()]--;
					s.pop();
				}
				cnt[p]--;
				s.pop();
			}
			s.push(p);
		}
		while(!s.empty())
		{
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
