#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
using namespace std;
void f()
{
	int n;
	long long m;
	cin >> n >> m;
	map<long long,long long> ma;
	vector<vector<long long> > dp1(n+1,vector<long long>(n+1));
	vector<vector<long long> > dp2(n+1,vector<long long>(n+1));
	vector<long long> x(n+1);
	for(int i = 1;i <= n;i++)
	{
		cin >> x[i];
	}
	int l = 1;
	long long cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		l = i;
		ma.clear();
		for(int j = i;j <= n;j++)
		{
			while(x[j]-x[l]>m && j >= l)
			{
				ma[dp1[i][l]]-=dp2[i][l];
				if(ma[dp1[i][l]] == 0) ma.erase(ma[dp1[i][l]]);
				l++;
			}
			if(ma.empty()) {ma[0] = dp2[i][j] = 1;continue;};
			dp1[i][j] = ma.begin() -> first+1;
			dp2[i][j] = ma.begin() -> second;
			//cerr << dp1[i][j] << ';' << dp2[i][j] << ' ';
			if(dp2[i][j] == 2) cnt++;
			ma[dp1[i][j]] += dp2[i][j];
		}
		//cerr << '\n';
	}
	cout << cnt << '\n';
	return;
}
int main()
{
	fre("migrate");
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--) f();
	return 0;
}