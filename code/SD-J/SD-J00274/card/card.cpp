#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[300005];
//int ton[300005];
int cnt[300005]={0};
bool vis[300005]={0};

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	for(int i=n; i>=1; i--)
	{
		
		for(int j=n+1-i; j<=n; j++)
		{
			if(vis[a[j]]==1)
			{
				int k=j-1;
				int op=k;
				while(k--){
					if(a[op]==a[j])
					{
						break;
					}
					vis[op]=0;
					op-=1;
				}
				continue;
			}
			vis[a[j]]=1;
		}
		for(int i=1; i<=m; i++)
		{
			if(vis[i]==1){
				cnt[i]++;
			}
			vis[i]=0;
		}
	}
	for(int i=1; i<=m; i++)
	{
		cout << cnt[i] << " ";
	}
	return 0;
}
