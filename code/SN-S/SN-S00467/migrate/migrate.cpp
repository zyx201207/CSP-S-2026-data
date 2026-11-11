#include <bits/stdc++.h>
#define int long long
#define N 2000010
//韩心尧 SN-S00467 西安市铁一中学 
using namespace std;

int c,T;
int n,d;
int pos[N];
int dis[N],dpl[N];
int ans;
int l,r;
//map<int,int> mp;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out ","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> T;
	for (int t = 1;t <= T;t++)
	{
		memset(dis,0x3f,sizeof(dis));
//		memset(dpl,0,sizeof(dpl));
		
		l = 1;
		ans = 0;
		cin >>n >> d;
		for (int i = 1;i <= n;i++)
		{
			cin >> pos[i];
		}
		for (int s = 1;s < n;s++)
		{
			
			
			//memset(dis,0x3f,sizeof(dis));
			memset(dpl,0,sizeof(dpl));
			l = s,r = s;
			dpl[s] = 1;
			dis[s] = 0;
			//printf("s = %d\n",s);
			for (r = s;r <= n;r++)
			{
				
				while (pos[r] - pos[l] > d)
				{
					l++;
				}
				for (int j = l;j < r;j++)
				{
				
					if (dis[j] < dis[r] - 1)
					{
						dis[r] = dis[j] + 1;
						dpl[r] = dpl[j];
						
					}
					else if (dis[j] == dis[r] - 1)
					{
						dpl[r]+= dpl[j];
						
					}
					//printf("j = %d dis[j] = %d dis[r] = %d dpl[j] = %ddpl[r] = %d\n",j,dis[j],dis[r],dpl[j],dpl[r]);
				}
				if (dpl[r] == 2)
				{
					ans++;
				}
				//printf("r = %d dpl[r] = %d\n",r,dpl[r]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
