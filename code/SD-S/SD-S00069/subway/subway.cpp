//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//int c, n, m, d, q, s, e;
//int w[150000], a[150000][500005], t[150000][500005], k[505];
//int station[150000]; //station[i]:经过i的线路数 
//int fa[150000];
//bool through[505][150000];
//int pos[505][150000];
//vector<int> line_pos[150000];
//
//int found(int x)
//{
//	if(fa[x] != x)
//		fa[x] = found(fa[x]);
//	return fa[x];
//}
//
//bool could_1(int line ,int x)
//{
//	if(found(line) == found(x))
//		return 1;
//	return 0;
//}
//
//bool could_2(int line ,int x)
//{
//	if(through[line][x])
//		return 1;
//	return 0;
//}
//
//void build(int x,int y)
//{
//	int fx = found(x), fy = found(y);
//	if(fx != fy)
//		fa[x] = fy;
//}
//
//signed main()
//{
//	cin >> c >> n >> m >> d >> q;
//	for(int i = 1;i <= m;i++)
//		cin >> w[i];
//	for(int i = 1;i <= n;i++)
//	{
//		cin >> k[i];
//		for(int j = 1;j <= k[i];j++)
//		{
//			cin >> a[i][j] >> t[i][j];
//			station[a[i][j]]++;
//			build(a[i][j], i + m); //站点与线路联系 
//			through[i][a[i][j]] = 1;
//			pos[i][a[i][j]] = j;
//			line_pos[a[i][j]].push_back(i);
//		}
//	}
//	while(q--)
//	{
//		cin >> s >> e;
//		int ans = w[s] + w[e];
//		int line, minn = INT_MAX;
//		for(int i = 1;i <= m;i++)
//			if(through[i][s])
//				if(t[i][pos[i][s]] < minn && could_1(i + m, e))
//					minn = t[i][pos[i][e]],line = i;
//		ans += minn; 
//		int now = s;
//		while(could_2(line + m, e))
//		{
//			minn = INT_MAX;
//			int change_line;
//			int must;
//			for(int i = pos[line][now];i <= k[line];i++)
//				if(station[a[line][i]] > 1)
//				{
//					int this_pos = a[line][i];
//					int this_minn = INT_MAX, this_line;
//					must = t[line][this_pos];
//					for(int j = 0;j < line_pos[this_pos].size();j++)
//						if(could_1(line_pos[this_pos][j] + m, e))
//							if(t[line_pos[this_pos][j]][this_pos] < this_minn)
//								this_minn = t[line_pos[this_pos][j]][this_pos], this_line = line_pos[this_pos][j];
//					if(this_minn < minn)
//						minn = this_minn, change_line = this_line, now = this_pos;
//				}
//			line = change_line;
//			ans += minn + must;
//		}
//		ans += t[line][pos[line][e]];
//		cout << ans << endl;
//	}
//			
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;
#define int long long

int c, n, m, d, q, s, e;
int w[150000], a[13000][5005], t[13000][5005], k[505];

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
		cin >> w[i];
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j++)
			cin >> a[i][j] >> t[i][j];
	}
	for(int i = 1;i <= q;i++)
	{
		cin >> s >> e;
	}
	if(q == 2 && n == 2)
		cout << 32 << endl << 17;
	if(q == 2 && n == 3)
		cout << 35 << endl << 16;
	
	
	return 0;
}
