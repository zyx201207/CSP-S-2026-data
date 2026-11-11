#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500010],kk,dis[510][510],ans,sum;
int to[1000010],ls[1000010],l[1000010],t[1000010],cnt;
void add(int x,int y,int z){
	to[++cnt]=y;
	l[cnt]=ls[x];
	ls[x]=cnt;
	t[cnt]=z;
}
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>kk;
		for(int j=1;j<=kk;j++){
			cin>>x>>y;
			add(i,x+n,y);
			add(x+n,i,y);
		}
	}
	memset(dis,0x3f3f3f3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		for(int j=ls[i];j;j=l[j]){
			for(int k=ls[to[j]];k;k=l[k]){
				dis[i][to[k]]=min(dis[i][to[k]],t[j]+t[k]);
			}
		}
		dis[i][i]=0;
	}
	floyd();
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=w[x]+w[y],sum=1e18;
		for(int i=ls[x+n];i;i=l[i]){
			for(int j=ls[y+n];j;j=l[j]){
				sum=min(sum,dis[to[i]][to[j]]+t[i]+t[j]);
			}
		}
		cout<<sum+ans<<"\n";
	}
	return 0;
}
