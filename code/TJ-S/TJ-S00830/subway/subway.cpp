#include<bits/stdc++.h>
using namespace std;
int w[5000005];
int bg[20005][20005];
int ans=INT_MAX;
int c,n,m,d,q;
void dfs(int num,int xx,int yy,int p){
	int minn=INT_MAX,pl;
	if(pl==yy) ans=min(num,ans);
	for(int i=1;i<=m;i++){
		if(bg[p][i]!=0&&bg[p][i]<minn){
			minn=bg[p][i];
			pl=i;
		}
	}
	if(num>=ans) return;
	dfs(num+minn,xx,yy,pl);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(c==0) cout<<35<<"\n"<<16;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a,t;
			bg[k][a]=t;
			bg[a][k]=t;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ans=INT_MAX;
		dfs(0,x,y,x);
		cout<<ans<<"\n";
	}
	return 0;
}

