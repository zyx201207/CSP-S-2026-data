#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using pii = pair<int,int>;
#define inf 1e18
using ull = unsigned long long;
using lf = double;
const int MAXN = 5e2 + 5,MAXK = 5e5 + 5,MAXQ = 1e5 + 5,MAXD = 25;

int c,n,m,d,q;
int wt[MAXN]; // 地铁口 -> 站厅的时间 
int a[MAXN][MAXK];
int t[MAXN][MAXK]; // 站厅 -> 站台的时间 
int ki[MAXN]; // 站台数 
vector<int>edge[MAXN];
int dp[MAXN];

int sum,sum1;

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) {
		sum1 += wt[i];
	}
	for (int i=1;i<=n;i++) {
		cin>>ki[i];
		for (int j=1;j<=ki[i];j++) {
			cin>>a[i][j]>>t[i][j];
			sum += t[i][j];
		}
	}
	cout<<sum<<endl;
	cout<<sum1<<endl;
	return 0;
}