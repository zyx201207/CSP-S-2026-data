#include <bits/stdc++.h>
using namespace std;
int c,m,n,d,q;
int w[100005];
struct node{
	int a;
	int t;
}p[10][100005];
struct st{
	int x;
	int y;
}plan[10005];
bool used[1000005];
int k[100005];
node trans[10005];
int num = 0;
int xx;
int yy;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> m >> n >> d >> q;
	for(int i = 1;i<=m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i<=n;i++)
	{
		cin >> k[i];
		for(int j = 1;j<=k[i];j++)
		{
			int a,t;
			cin >> a >> t;
			if(!used[a]) used[a] = 1;
			else
			{
				num++;
				trans[num].a = a;
				trans[num].t = t;
			}
			p[i][j].a = a;
			p[i][j].t = t;
		}
		for(int i = 1;i<=q;i++)
		{
			cin >> plan[i].x >> plan[i].y;
		}
		if(c==21 ||c==20)
		{
			
			int ans = 0;
			for(int z = 1;z<=q;z++)
			{
				bool flag = 0;
				xx = plan[z].x;
				yy = plan[z].y;
				ans=w[xx]+w[yy];
				for(int i = 1;i<=n;i++)
				{
					bool flagx = 0,flagy = 0;
					for(int j = 1;j<=k[i];j++)
					{
						if(p[i][j].a == xx)
						{
							ans+=p[i][j].t;
							flagx = 1;
						}
						if(p[i][j].a == yy)
						{
							ans+=p[i][j].t;
							flagy = 1;	
						}
					}
					if(flagx&&flagy)
					{
						flag = 1;
					}
				}
				if(flag)	cout << ans << endl;
			}
		}
	}
	return 0;
}
