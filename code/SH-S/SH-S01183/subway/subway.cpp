#include<bits/stdc++.h>
using namespace std;
struct node{
	long long to,w;
};
long long c,n,m,d,q,t1[10010],t2[10010][10010],dp[10010][10010],x,y;
vector<int>s[10010];
vector<int>st[10010];
vector<node>g[10010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>t1[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			long long as,ts;
			cin>>as>>ts;//as是地铁站编号 ts是as站和地铁i的距离 
			s[i].push_back(as);
			st[as].push_back(i);
			t2[as][i]=ts;//t2是地铁站到线的距离 
		}
	}
	for(int i=1;i<=m;i++){
		for(auto x:st[i]){//x:name of subway
			for(int j=0;j<s[x].size();j++){
				dp[i][s[x][j]]=min(dp[i][s[x][j]],t2[i][x]+t2[s[x][j]][x]);
				dp[s[x][j]][i]=min(dp[i][s[x][j]],dp[s[x][j]][i]);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<dp[x][y]+t1[x]+t1[y]<<endl;
	}
	
	return 0;
}
