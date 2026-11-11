//SN-S00477 于柏骁 西安辅轮中学 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6+5;
int c;
int n,d;
int x[maxn];
void solve()
{
	cin >> n >> d;
	for(int i = 1;i <= n;i ++) cin >> x[i];
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T=1;
	cin >> c >> T;
	while(T--) solve();
	return 0;
}
