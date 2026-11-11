#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
struct node
{
	int id;
	int a;
	long long t;
}sta[505];
int q;
int n,m;
int c,d;
long long w[N];  //地铁口到站厅 
int num[505];  //地铁经过站数 
long long tot;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	int cnt = 1;
	for (int i = 1;i <= n;i++)
	{
		cin >> num[i];
		for (int j = 1;j <= num[i];j++)
		{
			sta[cnt].id = i;
			cin >> sta[cnt].a >> sta[cnt].t;
			cnt++;
		}
	}
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		tot += w[x];
		for (int i = 1;i <= n;i++)
		{
			if (sta[i].a == x)
			{
				tot += sta[i].t;
			}
		}
		cout << tot + 20 << endl;
	}
	return 0;
}
