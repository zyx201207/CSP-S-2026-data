#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],v[500005],t[500005],vel[500005];
long long dp[1005][1005],a[1005][1005];
vector<int>fa[500005],son[500005];
void work(int uu,int vv,int tmp){
	memset(vel,0,sizeof(vel));
	queue<int>qu,qt;
	qu.push(uu),qt.push(1);
	while(!qu.empty()){
		int nu=qu.front(),nt=qt.front();
		qu.pop(),qt.pop();
		if(vel[nu])continue;
		vel[nu]=nt;
		if(nu==vv)break;
		for(int i=0;i<fa[nu].size();i++){
			for(int j=0;j<son[fa[nu][i]].size();j++){
				int nv=son[fa[nu][i]][j];
				if(!vel[nv]){
					qu.push(nv),qt.push(nt+1);
				}
			}
		}
	}
	cout<<2*(vel[vv]-1)*tmp<<endl;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	if(m<=1000){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i!=j)a[i][j]=INT_MAX;
			}
		}
		while(n--){
			int k;
			scanf("%d",&k);
			for(int i=1;i<=k;i++){
				scanf("%d%d",&v[i],&t[i]);
			}
			for(int i=1;i<=k;i++){
				for(int j=i+1;j<=k;j++){
					a[v[i]][v[j]]=min(a[v[i]][v[j]],t[i]+t[j]);
					a[v[j]][v[i]]=min(a[v[j]][v[i]],t[i]+t[j]);
				}
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i!=j)dp[i][j]=INT_MAX;
				if(a[i][j])dp[i][j]=a[i][j];
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
			int uu,vv;
			scanf("%d%d",&uu,&vv);
			cout<<dp[uu][vv]+w[uu]+w[vv]<<endl;
		}
	}else{
		int tmp;
		for(int l=1;l<=n;l++){
			int k,u;
			scanf("%d",&k);
			for(int i=1;i<=k;i++){
				scanf("%d%d",&u,&tmp);
				fa[u].push_back(l);
				son[l].push_back(u);
			}
		}
		while(q--){
			int uu,vv;
			scanf("%d%d",&uu,&vv);
			work(uu,vv,tmp);
		}
	}
	return 0;
}
