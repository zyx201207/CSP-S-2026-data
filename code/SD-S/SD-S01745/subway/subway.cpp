#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,n,m,D,q,a[500005],ans,x,y,vst[500005];
vector<pair<int,int> > b[505],e[500005];
void dfs(int u,int fa,int sum){//cout<<"fa="<<fa<<", u="<<u<<", sum="<<sum<<"\n";
	if(u==y){
		ans=min(ans,sum);return ;
	}
//	sum+=e[fa][].second;
	vst[u]=1;
	for(int i=0;i<e[u].size();i++){
		int f=e[u][i].first,ww=0;
		if(f==fa)continue;
		for(int j=0;j<b[f].size();j++){
			int v=b[f][j].first,w=b[f][j].second;
			if(v==u)ww=w;
		}
		for(int j=0;j<b[f].size();j++){
			int v=b[f][j].first,w=b[f][j].second;
			if(vst[v])continue;
			dfs(v,f,sum+ww+w);
			
		}
		
		
		
	}
	
	
	
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&C,&n,&m,&D,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int k,ai,ti;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&ai,&ti);
			e[ai].push_back(make_pair(i,0));
//			for(int ii=0;ii<b[i].size();ii++){
//				int v=b[i][ii].first,w=b[i][ii].second;
//				e[ai].push_back(v,ti);
//				e[v].push_back(ai,w);
//			}
			b[i].push_back(make_pair(ai,ti));
		}
	}
//	for(int i=1;i<=m;i++){cout<<i<<": ";
//		for(int j=0;j<e[i].size();j++){
//			cout<<e[i][j].first<<" ";
//		}cout<<"\n";
//	}cout<<"\n";
	
	
	while(q--){ans=1e9;
		for(int i=1;i<=m;i++){
			vst[i]=0;
		}
		scanf("%lld%lld",&x,&y);
		for(int i=0;i<e[x].size();i++){
			int f=e[x][i].first,ww=0;
			for(int j=0;j<b[f].size();j++){
				int v=b[f][j].first,w=b[f][j].second;
				if(v==x)ww=w;
			}
			for(int j=0;j<b[f].size();j++){
				int v=b[f][j].first,w=b[f][j].second;
				if(vst[v])continue;
				dfs(v,f,ww+w);
			}
			
			
//			dfs(x,e[x][i].first,0ll);
//			cout<<"\n";
		}
		
		printf("%lld\n",ans+a[x]+a[y]);
	}
	
	
	return 0;
}
