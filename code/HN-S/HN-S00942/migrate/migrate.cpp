#include <bits/stdc++.h>
using namespace std;
#define int long long
#define wabs(x) ((x)<0 ? -(x) : (x))
const int Llmax=0x3f3f3f3f3f3f3f;

#define xx migrate__name__0

const int N=2e6;
int xx[N+105];
vector <int> pict[N+105];

deque <int> xl;
int dis[N+105],cnt[N+105];
void spfa (int n, int st)
{
	for (int i=1; i<=n; i++)
	{
		dis[i]=Llmax,cnt[i]=0;
	}
	dis[st]=0,cnt[st]=1;
	xl.push_back(st);
	while (xl.size())
	{
		int now=xl.front(); xl.pop_front();
		for (int i=0; i<pict[now].size(); i++)
		{
			int next=pict[now][i];
			if (dis[now]+1<dis[next])
			{
				dis[next]=dis[now]+1;
				cnt[next]=1;
				xl.push_back(next);
			}
			else if (dis[now]+1==dis[next])
			{
				cnt[next]++;
			}
		}
	}
//	printf("st: %lld\n",st);
//	for (int i=1; i<=n; i++)
//	{
//		printf("%lld ",dis[i]);
//	}
//	printf("\n");
//	for (int i=1; i<=n; i++)
//	{
//		printf("%lld ",cnt[i]);
//	}
//	printf("\n");
	return;
}

signed run ()
{
	int n,d;
	cin >> n >> d;
	for (int i=1; i<=n; i++)
	{
		pict[i].clear();
	}
	for (int i=1; i<=n; i++)
	{
		cin >> xx[i];
	}
//	sort(xx+1,xx+n+1);
//	cout << "||| "; //MS v
//	for (int i=1; i<=n; i++)
//	{
//		cout << xx[i] << " ";
//	}
//	cout << "---\n"; //MS ^
//	for (int i=1; i<=n; i++)
//	{
//		for (int j=i+1; j<=n; j++)
//		{
//			if (xx[j]-xx[i]<=d)
//			{
//				pict[i].push_back(j);
//				pict[j].push_back(i);
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++) if (i!=j)
		{
			if (wabs(xx[j]-xx[i])<=d)
			{
				pict[i].push_back(j);
//				pict[j].push_back(i);
			}
//			else
//			{
//				break;
//			}
		}
	}
	
//	cout << "\n"; //MS v
//	for (int i=1; i<=n; i++)
//	{
//		cout << i << ": ";
//		for (int j=0; j<pict[i].size(); j++)
//		{
//			cout << pict[i][j];
//		}
//		cout << "--\n";
//	} //MS ^
	
	int sum=0;
	for (int i=1; i<=n; i++)
	{
		spfa(n,i);
		for (int j=i+1; j<=n; j++)
		{
			if (cnt[j]==2)
			{
				sum++;
			}
		}
	}
	cout << sum;
	return 0;
}

signed main ()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int c,t;
	cin >> c >> t;
	while (t--)
	{
		run();
		cout << "\n";
	}
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2
*/

/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1
*/
