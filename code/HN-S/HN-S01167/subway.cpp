#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const long long inf=1e13;
struct node{
	int id,t;
};
const int N=510;
int dp[N][N];
int w[500010];
vector<node> wi[N];
int c,n,m,d,q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			wi[k].push_back({a,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<x+y<<"\n";
	}
	return 0;
}

