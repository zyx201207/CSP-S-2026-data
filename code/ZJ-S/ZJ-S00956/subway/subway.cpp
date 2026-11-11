#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=2e6+10;
long long c,n,m,d,q,w[N],k[1000],a[505][20005];
long long x,y,t[505][20005],ans=1e18,mp[500005],ma[505]; 
vector<long long> vec[500005];
void dfs(long long r,long long w){
	mp[r]=1;
	if(r==y){
		ans=min(ans,w);
		return;
	}
	for(int i=0;i<vec[r].size();i++){
		long long v=vec[r][i];
		if(!ma[v]){
			ma[v]=1;
			for(int j=1;j<=k[v];j++){
				if(!mp[a[v][j]]){
					dfs(a[v][j],w+1);
					mp[a[v][j]]=0;
				}
			}
		}
	}
}
void dfs2(long long r,long long w){
	mp[r]=1;
	if(r==y){
		ans=min(ans,w);
		return;
	}
	for(int i=0;i<vec[r].size();i++){
		long long v=vec[r][i];
		if(!ma[v]){
			ma[v]=1;
			long long l=0;
			for(int j=1;j<=k[v];j++){
				if(a[v][j]==r){
					l=j;break;
				}
			}
			for(int j=1;j<=k[v];j++){
				if(!mp[a[v][j]]){
					dfs2(a[v][j],w+t[v][l]+t[v][j]);
					mp[a[v][j]]=0;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld&lld",&a[i][j],&t[i][j]);
			vec[a[i][j]].push_back(i);
		}
	}
	while(q--){
		ans=1e18;
		for(int i=1;i<=m;i++)mp[i]=0;
		memset(ma,0,sizeof(ma));
		cin>>x>>y;
		if(c<=8){
			dfs2(x,0);
			cout<<ans+w[x]+w[y]<<"\n";
		}else{
			dfs(x,1);
			cout<<w[x]+w[y]+2*(ans-1)*t[1][1]<<"\n";
		}
	}
	return 0;
}
