#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n,m,d,q,w[500005],k[505],x,y,dp[500005],z;
vector<int> b[500005],c[500005],a[505],t[505];
bool is[500005];
void dg(){
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		z=q.front(),q.pop(),is[z]=0;
		for(int i=0;i<b[z].size();i++){
			if(!is[b[z][i]] && (dp[b[z][i]]==-1 || dp[b[z][i]]>dp[z]+c[z][i])){
				is[b[z][i]]=1,dp[b[z][i]]=dp[z]+c[z][i],q.push(b[z][i]);
			}
			dp[b[z][i]]=min(dp[b[z][i]],dp[z]+c[z][i]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>x>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			a[i].push_back(x),t[i].push_back(y);
		}
		for(int j=0;j<k[i];j++){
			for(int l=j+1;l<k[i];l++){
				b[a[i][l]].push_back(a[i][j]);
				b[a[i][j]].push_back(a[i][l]);
				c[a[i][j]].push_back(t[i][j]+t[i][l]);
				c[a[i][l]].push_back(t[i][j]+t[i][l]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		memset(dp,-1,sizeof dp);
		memset(is,0,sizeof is);
		dp[x]=0,is[x]=1;
		dg();
		cout<<dp[y]+w[x]+w[y]<<endl;
	}
	return 0;
}
