#include <bits/stdc++.h>
using namespace std;
#define int long long
int m,n,c,d,q,w[500001],sum,minn=100000000,x,k,ff[500001],r,jg[100001],cnt,tn[50001][50001],tt[50001][50001];
struct node
{
	int a,t;
}z[500001];
struct nodee
{
	int zc,f;
}to[500001];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			cin >> z[j].a >> z[j].t;
//			ff[z[j].a]++;
//			int pn,pt;
//			if(j % 2 != 0)
//			{
//				tn[i][++pn] = z[j].a;
//			}
//			else
//			{
//				tt[i][++pt] = z[j].t;
//			}
			if(to[z[j].a].f >= 1)
			{
				//minn = min(to[z[j].a].zc,z[j].t);
				to[z[j].a].zc += z[j].t;
			}
			else
			{
				to[z[j].a].f++;
				to[z[j].a].zc = z[j].t;
			}
			//cout << to[z[j].a].zc;
			//cout << to[z[j].a].f;
			
		}
	}
//	while(q--)
    for(int i = 1;i <= q;i++)
	{
		cin >> x >> r;
//		for(int i = 1;i <= n;i++)
//	    {
//		    for(int j = 1;j <= k;j++)
//		    {
//		    	if(tn[i][j] == r)
//				{
//					sum += tt[i][j];
//					break;	
//				}
//		    	if(x<=tn[i][j] and tn[i][j] <= r)
//		    	{
//		    		sum += tt[i][j];
//				}
//			}
//        }
		sum += w[x] + w[r];
		for(int j = x;j <= r;j++)
		{
			//cout << to[i].zc;
			sum += to[j].zc;
		}
    int cnt;
		jg[i]=sum;
	}
	for(int i = 1;i <= q;i++)
	{
		cout << jg[i] << endl;
	}
	return 0;
}
