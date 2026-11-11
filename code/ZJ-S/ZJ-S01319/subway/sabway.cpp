#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
struct stu{
	int u,l;
};
int dis[510][510];
int w[500010];
int a[500010];
int b[500010];
int t[500010];
int t2[500010];
int ta[500010];
int tb[500010];
void SP2(){
	int k1,k2;
	int minh=1e10;
	cin>>k1;
	for(int i=1;i<=k1;i++){
		cin>>a[i];
		cin>>t[a[i]];
	}
	cin>>k2;
	for(int i=1;i<=k2;i++){
		cin>>b[i];
		cin>>t[b[i]];
		if(t[b[i]]){
			minh=min(minh,t[b[i]]+t2[b[i]]);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e10; 
		if(t[x]&&t[y])ans=min(ans,w[x]+w[y]+t[x]+t[y]);
		if(t2[x]&&t2[y])ans=min(ans,w[x]+w[y]+t2[x]+t2[y]);
		if(t[x]&&t2[y])ans=min(ans,w[x]+w[y]+t[x]+t2[y]+minh);
		if(t2[x]&&t[y])ans=min(ans,w[x]+w[y]+t2[x]+t[y]+minh);
		cout<<ans<<'\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(dis,0x3f,sizeof dis);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(n==20||n==21){
		SP2();
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>a[i]>>t[i];
		}
		for(int i=1;i<=k;i++){
			for(int j=i+1;j<=k;j++){
				int x=a[i],y=a[j];
				if(x>=y)swap(x,y);
				dis[x][y]=min(dis[x][y],t[i]+t[j]);
			}
		}
	}
	for(int ii=1;ii<=m;ii++){
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				for(int k=1;k<=m;k++){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x>=y)swap(x,y);
		cout<<dis[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
} 
