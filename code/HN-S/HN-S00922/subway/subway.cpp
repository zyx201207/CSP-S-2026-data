#include<bits/stdc++.h>
using namespace std;
const int N = 401, K = 5e4+10;
#define ull unsigned long long

int c,n,m,d,q;
int w[N],k[N],a[N][K],t[N][K],vis[N];
vector<int> pass[N];
int dfs(int s,int e,int sum){
	if(s==e)return sum;
	for(int i=0;i<pass[s].size();i++){
		for(int j=1;j<=k[i];j++){
			if(vis[j])continue;
			vis[j]=1;
			if(j==s)continue;
			return dfs(a[i][j],e,sum+w[s]+w[i]+t[i][j]);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			pass[a[i][j]].push_back(i);
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		cout<<dfs(x,y,0)<<"\n";
	}
	return 0;
}
