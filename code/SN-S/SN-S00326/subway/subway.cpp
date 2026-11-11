//高一轩 西安铁一中滨河高级中学 SN-S0036 
#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],mp[2000][2000],t[2000],a[2000],ans,an,x,y;
bool vis[2000];
void dfs (int s)
{
	if(s==y)
	{ans = min(ans,an);return;}
	for(int i = 0;i<2000;i++)
	{
		if(mp[s][i]==0||vis[i] == 1)
			continue;
		vis[i] = 1;
		an += mp[s][i];
		dfs(i);
		vis[i] =0;
		an -= mp[s][i];
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 0 ;i<m;i++)
	{
		cin >> w[i];
	}
	for(int i = 0;i<n;i++)
	{
		int k = 0;cin >> k;
		for(int j =0;j<k;j++)
		{
			cin >> 	a[j] >> t[j];
			a[j]--;	
		}
			//if(mp[a[j]][a[j+1]] != 0 && mp[a[j]][a[j+1]]<t[j] + t[j+1])
				//continue;
			/*mp[a[j]][a[j+1]] = t[j] + t[j+1];
			mp[a[j+1]][a[j]] = t[j] + t[j+1];*/
		for(int l = 0;l<k;l++)
			for(int r = 0;r<k;r++)
			{
				if(l == r)
					{continue;}
				if(mp[a[l]][a[r]] != 0 && mp[a[l]][a[r]] < t[l] + t[r])
					{continue;}
				mp[a[l]][a[r]] = t[l] + t[r];
				mp[a[r]][a[l]] = t[l] + t[r]; 
			}
	}
	/*for(int i = 0;i<m;i++)
	{
		cout << "\n";
		for(int j = 0;j<m;j++)
			cout << mp[i][j] << " ";
	}*/
	while(q--)
	{
		for(int i = 0;i<2000;i++)
		{
			vis[i] = 0;
		}
		cin >> x >> y;
		ans = 999999999999;an = 0;
		x--;y--;
		vis[x] = 1;
		dfs(x);
		cout << ans + w[x] + w[y] << "\n";		
	}
	return 0;
	/*记得long long,文件注释*/
}
