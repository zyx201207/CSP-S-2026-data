#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1000,M=1e3+1000;
long long c,n,m,d,q,k,w[N],b[M][M];
long long head[N],e[N],ver[N],nxt[N],tot,zz[N],x,y,ans=1000000000000000;
void add(long long x,long long y,long long z){
	ver[++tot]=y;
	zz[tot]=z;
	nxt[tot]=head[x];
	head[x]=tot;
}
void dfs(long long hh,long long xx,long long way,long long sum){
	//cout<<hh<<" "<<xx<<" "<<way<<" "<<sum<<"\n";
	if(xx==y){
		sum+=b[xx][way];
		ans=min(ans,sum);
		return;
	}
	for(int i=head[xx];i;i=nxt[i]){
		int yy=ver[i],ww=zz[i];
		if(yy==hh)continue;
		if(ww==way){
			dfs(xx,yy,way,sum);
		}
		else{
			//cout<<sum<<" "<<b[xx][way]<<" "<<b[yy][ww]<<"     ";
			dfs(xx,yy,ww,sum+b[xx][way]+b[xx][ww]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			long long a;
			cin>>e[j]>>a;
			b[e[j]][i]=a;
			//cout<<e[j]<<" "<<i<<" "<<b[e[j]][i]<<"\n";
			if(j!=1){
				add(e[i],e[j-1],i);
				add(e[j-1],e[j],i);
			}
		}
	}
	for(int i=1;i<=q;i++){
		ans=2147483647;
		cin>>x>>y;
		for(int i=head[x];i;i=nxt[i]){
			dfs(x,ver[i],zz[i],b[x][zz[i]]);
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
