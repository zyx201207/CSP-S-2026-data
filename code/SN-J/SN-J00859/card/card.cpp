#include <bits/stdc++.h>
#include <queue>
using namespace std;
int n,m;
int a[100005];
//int ans[100005];
//int Q[100005];
//int vis[100005];
int M[100005];
//int check(int x,int cnt)
//{
//	for(int i = 1; i <= cnt; i++)
//	{
//		if(Q[i] == x) return i;
//	}
//	return 0;
//}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		M[a[i]] = i;
	}
//	for(int i = 1; i <= n; i++)
//	{
//		memset(vis,0,sizeof(vis));
//		int cnt = 1;
//		for(int j = i; j <= n; j++)
//		{
//			if(!check(a[j],cnt))
//			{
//				Q[cnt] = a[j];
//				cnt++;
//			}
//			else if(check(a[j],cnt))
//			{
//				for(int k = check(a[j],cnt); k <= cnt - 1; k++)
//				{
//					Q[k] = Q[k + (cnt - check(a[j],cnt))];
//				}
//				cnt -= (cnt - check(a[j],cnt));
//				Q[cnt] = a[j];
//			}
//		}
//		for(int j = 1; j <= cnt; j++) cout << Q[i] << " ";
//		cout << "\n";
//		for(int j = 1; j <= cnt; j++)
//		{
//			if(vis[i] == 0)
//			{
//				ans[i]++;
//				vis[i] = 1;	
//			}
//		}
//	}
	for(int i = 1; i <= m; i++) cout << M[i] << " ";
	return 0;
}
