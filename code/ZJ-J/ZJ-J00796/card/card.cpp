#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int sum[N];
int ans[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(sum,0,sizeof(sum));
		int g[N],top=0;
		for(int j=i;j<=n;j++)
		{
			if(sum[a[j]])
			{
				while(g[top]!=a[j])
				{
					sum[g[top]]--;
					top--;
				}
			}else{
				g[++top]=a[j];
				sum[a[j]]++;
			}
		}
		while(top)
		{
			ans[g[top]]++;
			top--;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
