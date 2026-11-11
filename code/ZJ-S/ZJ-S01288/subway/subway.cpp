#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,dp[1005][505],a[505][1005],t[505][1005];
int vis[505];
int w[1005],kk[505];
int u,v;
map<int,vector<pair<int,int> > >mp;
map<pair<int,int>,int>mp2;
int strange_hash(){
	hash<string>h;
	stringstream ss;
	string str;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			ss<<dp[i][j];
		}
	}
	ss>>str;
	return h(str);
}
signed main(){
	// maybe 24 pts
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>kk[i];
		for(int j=1;j<=kk[i];j++){			
			cin>>a[i][j]>>t[i][j];
			mp[a[i][j]].push_back(make_pair(i,t[i][j]));
			mp2[make_pair(a[i][j],i)]=t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>u>>v;
		memset(dp,0x3f,sizeof dp);
		for(int j=1;j<=m;j++){
			for(pair<int,int> k:mp[u]){
				dp[u][k.first]=k.second;
			}
		}
		int nhash=-1,lsthash=0;
		while(nhash!=lsthash){
			for(int j=1;j<=m;j++){
				for(int k=1;k<=n;k++){
					if(mp2[make_pair(j,k)]==0){
						continue;
					}
					for(int l=1;l<=kk[k];l++){
//						cerr<<"(OP1)"<<j<<" "<<k<<" "<<a[k][l]<<" "<<k<<" "<<dp[a[k][l]][k]<<endl;
						dp[j][k]=min(dp[j][k],dp[a[k][l]][k]);
					}
					for(pair<int,int> l:mp[j]){
//						cerr<<"(OP2)"<<j<<" "<<k<<" "<<dp[j][l.first]+l.second+mp2[make_pair(j,k)]<<endl;
						dp[j][k]=min(dp[j][l.first]+l.second+mp2[make_pair(j,k)],dp[j][k]);
					}
				}
			}
			lsthash=nhash;
			nhash=strange_hash();
		}
//		for(int j=1;j<=m;j++){
//			for(int k=1;k<=n;k++){
//				cerr<<dp[j][k]<<" ";
//			}
//			cerr<<endl;
//		}
		int ans=INT_MAX;
		for(pair<int,int> j:mp[v]){
//			cerr<<v<<" "<<j.first<<" "<<j.second<<endl;
//			cerr<<dp[v][j.first]+j.second<<endl;
			ans=min(ans,dp[v][j.first]+j.second);
		}
		cout<<ans+w[u]+w[v]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}