#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int x,y;
long long w[510000];
struct data{
	int k;
	long long a[51000],t[51000];
}b[510];
long long ans=LONG_LONG_MAX;
int vis[510];
bool check(int t,int now){
	for(int i=1;i<=b[t].k;i++){
		if(b[t].a[i]==now)return true;
	}
	return false;
}
void dfs(int now,long long s){
	if(s>=ans)return ;
	if(now==y){
		ans=min(ans,s+w[y]);
	}
	vis[now]=1;
	for(int j=1;j<=n;j++){
		if(check(j,now)){
			for(int i=1;i<=b[j].k;i++){
				if(vis[b[j].a[i]]==0){
					vis[b[j].a[i]]=1;
					s+=b[j].t[i-1]+b[j].t[i];
					dfs(b[j].a[i],s);
					vis[b[j].a[i]]=0;
					s-=b[j].t[i-1]+b[j].t[i];
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>b[i].k;
		for(int j=1;j<=b[i].k;j++)cin>>b[i].a[j]>>b[i].t[j];
	}
	while(q--){
		cin>>x>>y;
		memset(vis,0,sizeof(vis));
		ans=LONG_LONG_MAX;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=b[i].k;j++){
				if(b[i].a[j]==x)dfs(b[i].a[j],w[i]);
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
