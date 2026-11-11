#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+10,M=5e5+10;
int c,n,m,d,q;
int w[M],mp[M][30],t[M][30],mins[N][N];
int solve1(int u, int v){
	int ans=INT_MAX;
	for(int i=1;i<=mp[u][0];i++){
		for(int j=1;j<=mp[v][0];j++){
			int ul=mp[u][i],vl=mp[v][j];
			ans=min(ans,t[u][i]+t[v][j]+mins[ul][vl]);
		}
	}
	ans+=w[u]+w[v];
	return ans;
}
int solve2(int u, int v){
	int ans=w[u]+w[v];
	if(mp[u][0]==2&&mp[v][0]==2){
		ans+=min(t[u][1]+t[v][1],t[u][2]+t[v][2]);
	}else if(mp[u][0]==2){
		if(mp[u][1]==mp[v][1]) ans+=t[u][1]+t[v][1];
		else ans+=t[u][2]+t[v][1];
	}else if(mp[v][0]==2){
		if(mp[u][1]==mp[v][1]) ans+=t[u][1]+t[v][1];
		else ans+=t[u][1]+t[v][2];
	}else if(mp[u][1]==mp[v][1]){
		ans+=t[u][1]+t[v][1];
	}else{
		ans+=t[u][1]+t[v][1]+mins[1][2];
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(mins,0x3f,sizeof(mins));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		mins[i][i]=0;
		int len; cin>>len;
		while(len--){
			int to,tim; cin>>to>>tim;
			mp[to][++mp[to][0]]=i;
			t[to][mp[to][0]]=tim;
			if(mp[to][0]>1){
				for(int j=1;j<mp[to][0];j++){
					int v=mp[to][j];
					mins[i][v]=mins[v][i]=min(mins[i][v],tim+t[to][j]);
				}
			}
		}
	}
	if(c==20||c==21){
		while(q--){
			int u,v; cin>>u>>v;
			cout<<solve2(u,v)<<endl;
		}
	}else{
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					mins[i][j]=min(mins[i][j],mins[i][k]+mins[k][j]);
				}
			}
		}
		while(q--){
			int u,v; cin>>u>>v;
			cout<<solve1(u,v)<<endl;
		}
	}
	return 0;
}
