#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cout<<n<<' ';
	vector<vector<int> >p;
	for(int st=n;st>=1;st--)
	{
		p[a[st]].push_back(st);
		for(int i=n;i>=st;i--)
		{
			if(p[i][p[i].size()-1]!=p[i][0])
			{
				int l=p[i][p[i].size()-1];
				for(int j=l;j<=n;j++)ans[j]++;
				break;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
 } 
