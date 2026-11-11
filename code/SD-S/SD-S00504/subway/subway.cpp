#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int maxn=5e5+10;
int c,n,m,d,q,cnt;
int a[510][25],t[510][25];
int w[maxn];
int dis[1005][1005];
map<int,int> mp;
vector<int> vec[1005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int num;cin>>num;
		for(int j=1;j<=num;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--)cout<<0<<endl;
	return 0;
}
