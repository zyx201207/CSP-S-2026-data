//SN-S00477 于柏骁 西安辅轮中学 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5+5;
int c,n,m,d,q;
int w[maxn];
vector<int> G[maxn];
void solve()
{
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++) cin >> w[i];
	for(int i = 1;i <= n;i ++)
	{
		int a;
		cin >> a;
		for(int j = 1;j <= 2*a;j ++)
		{
			int x;
			cin >> x;
		} 
	}
	for(int Q = 1;Q <= q;Q ++)
	{
		int x,y;
		cin >> x >> y;
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T=1;
//	cin >> T;
	while(T--) solve();
	return 0; 
}
