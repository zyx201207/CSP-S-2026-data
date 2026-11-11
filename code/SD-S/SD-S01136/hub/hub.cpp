#include<bits/stdc++.h>
#define ll long long
#define N 1001000
const ll INF=1e18;
using namespace std;
ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
ll C,t,n,k,l,r,cnt,ans,a[N],s[N],f[N][31],c[N][25],dep[N];vector<ll>v[N];bool vis;
void dfs_tr(int u,int fa){
	dep[u]=dep[fa]+1;f[u][0]=fa;
	for(int i=1;(1<<i)<=dep[u];++i)
		f[u][i]=f[f[u][i-1]][i-1],c[u][i]=c[u][i-1]+c[f[u][i-1]][i-1];
	for(auto g:v[u])
		if(g!=fa)c[g][0]=1,dfs_tr(g,u);
}
ll dis(int u,int v){
	if(dep[u]<dep[v])swap(u,v);ll ans=0;
	for(int i=21;i>=0;--i)
		if(dep[u]-dep[v]>=(1<<i))ans+=c[u][i],u=f[u][i];
	if(u==v)return ans;
	for(int i=21;i>=0;--i)
		if(f[u][i]!=f[v][i])ans+=c[u][i]+c[v][i],u=f[u][i],v=f[v][i];
	return ans+c[u][0]+c[v][0];
}
void dfs(int x,int len){
	if(len==k+1){
		for(int i=1;i<=n;++i)s[i]=0;for(int i=1;i<=k;++i)s[a[i]]=1;cnt=0;
		dfs_tr(1,0);
		if(cnt<=2){
			ll res=0;
			for(int i=1;i<=k;++i)
				for(int j=i+1;j<=k;++j)res=max(res,dis(a[i],a[j]));
			ans=min(ans,res);
		}
		return ;
	}
	if(n-x<k-len)return ;
	for(int j=x;j<=n;++j)a[len]=j,dfs(j+1,len+1); 
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	C=read(),t=read();
	while(t--){
		n=read(),k=read(),ans=INF;vis=true;
		for(int i=1;i<=n-1;++i){
			l=read(),r=read();
			if(i<=n/2&&(l!=i||r!=i+1))vis=false;
			if(i>n/2&&(l!=i-n/2||r!=i+1))vis=false;
			v[l].push_back(r);
			v[r].push_back(l);
		}
		if(k==2){
			cout<<"1\n";
			for(int i=1;i<=n;++i)v[i].clear();
			continue;
		}
		if(vis){
			cout<<(k+1)/2-1<<"\n";
			for(int i=1;i<=n;++i)v[i].clear();
			continue;
		}
		dfs(1,0);
		cout<<ans<<"\n";
		for(int i=1;i<=n;++i)v[i].clear(); 
	} 
	return 0;
}

