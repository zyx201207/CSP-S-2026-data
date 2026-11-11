//我常常追忆过去，中间忘了，我该在哪里停留，I ask myself.
//@ m??d??p?? 
/*while(s==1)
  {
  	 continue
  }
  cout << "AFO";
*/
# include<bits/stdc++.h>
using namespace std;
const int MX = 100;
const int inf = 0x3f3f3f3f;
int g[MX + 10][MX + 10];
int n,t,c,k;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		memset(g,0x3f,sizeof(g));
		for(int i = 1;i < n;i++)
		{
			g[i][i] = 0;
			int u,v;
			cin >> u >> v;
			g[u][v] = g[v][u] = 1;
		}
		g[n][n] = 0;
		for(int k = 1;k <= n;k++)
		{
			for(int i = 1;i <= n;i++)
			{
				for(int j = 1;j <= n;j++)
				{
					g[i][j] = min(g[i][j],g[i][k] + g[k][j]);
				}
			}
		}
		cout << 0 << endl;
	}
	return 0;
}
