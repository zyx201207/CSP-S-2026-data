#include <iostream>
using namespace std;
const int N = 5e3 + 5;
const int INF = 0x3f3f3f3f;
int c,t,n,d;
int a[N];
struct infor{
	int way,len;//最短路数量、长度 
};
infor dis[N][N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
		}
		for(int i = 1;i<n;i++)
		{
			for(int j = i+1;j<=n;j++)
			{
				dis[i][j].len = INF;
			}
		}
		for(int i = 1;i<n;i++)
		{
			for(int j = i+1;j<=n;j++)
			{
				if(a[j] - a[i] <= d)
				{
					dis[i][j].len = 1;
					dis[i][j].way = 1;
				}else
				{
					break;
				}
			}
		}//计算一次就能飞到的位置
		for(int i = 1;i<n;i++)
		{
			for(int j = i+1;j<=n;j++)
			{
				for(int k = i+1;k<j;k++)
				{
					if(dis[i][k].len && dis[k][j].len)
					{
						if(dis[i][k].len+dis[k][j].len < dis[i][j].len)
						{
							dis[i][j].len = dis[i][k].len+dis[k][j].len;
							dis[i][j].way = 1;
						}else if(dis[i][k].len+dis[k][j].len == dis[i][j].len)
						{
							dis[i][j].way++; 
						}
					}
				}
			}
		}
		long long ans = 0;
		for(int i = 1;i<n;i++)
		for(int j = i+1;j<=n;j++)
		if(dis[i][j].way == 2)
		ans ++;
		cout << ans << endl;
	}
}