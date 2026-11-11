#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1e5+5,inf=1e9;
int d[105][105],fa[105];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
map<int,int>mp;
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) d[i][j]=inf;
		d[i][i]=0;
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		d[u][v]=d[v][u]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		}
	}
	int ans=inf;
	for(int i=0;i<(1<<n);i++){
		int t=0;
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))) t++;
			fa[i]=i;
		}
		if(t!=k) continue;
		int asi=0;
		for(int j=1;j<=n;j++){
			int asj=inf,p=0;
			for(int k=1;k<=n;k++){
				if(j!=k&&(i&(1<<(k-1)))&&asj>d[j][k]){
					asj=d[j][k];
					p=k;
				}
			}
			if(i&(1<<(j-1))){
				if(asj==1) fa[find(j)]=find(p);
			}else asi=max(asi,asj);
		}
		t=0;
		mp.clear();
		for(int j=1;j<=n;j++){
			if((i&(1<<(j-1)))&&mp[find(j)]==0) mp[find(j)]=++t;
		}
		if(t<=2) ans=min(ans,asi);
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		if(c<=3) solve();
	}
	//18:12
	/*
	I have already ranjin, WC is unbelievable.
	*/
	return 0;
}
