#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],cnt[N],vis[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	if(n>=501)
	{
		for(int i=1;i<=m;i++) cout<<upper_bound(a+1,a+n+1,i)-a-1<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			for(int k=i;k<j;k++)
			{
				if(!vis[k]&&a[k]==a[j])
				{
					//cout<<k<<" ";
					for(int p=k;p<j;p++)
					{
						vis[p]=1;
					//	cout<<i<<" "<<p<<endl; 
					}
					break;
				}
			}
		}
		for(int y=i;y<=n;y++)
		{
			if(!vis[y]) cnt[a[y]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
 } 
 /*
 10 3
3 1 2 1 3 2 3 1 2 1
*/
