#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll read(){
	ll f=1,x=0,c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
ll c,t;
ll n,k; 
vector<ll>a[100007];
ll fl[100007],dep[100007],f[100007][27];
void dfs1(ll u,ll fa){
	for(ll v:a[u]){
		if(v==fa)continue;
		dep[v]=dep[u]+1;
		f[v][0]=u;
		for(int i=1;i<27;i++){
			f[v][i]=f[f[v][i-1]][i-1];
		}
		dfs1(v,u);
	}
}
ll lca(ll u,ll v){
	if(dep[u]<=dep[v]){
		swap(u,v);
	}
	for(int i=26;i>=0;i--){
		if(dep[f[u][i]]>=dep[v])u=f[u][i];
	} 
	if(u==v)return u;
	for(int i=26;i>=0;i--){
		if(f[u][i]!=f[v][i])u=f[u][i],v=f[v][i];
	}
	return f[u][0];
}
bool dfs(ll cnt,ll tot,ll u,ll mid,ll fa){
	if(cnt>=3||tot>k)return 0;
//	cout<<cnt<<' '<<tot<<' '<<u<<' '<<mid<<endl;
	if(tot==k){
//		cout<<"!!!!!\n";
		bool flag=1;
		for(ll j=1;j<=n;j++){
			ll res=0;
			for(ll i=1;i<=n;i++){
				if(fl[i]==0||fl[j]==1)continue;
				if(dep[i]+dep[j]-2*dep[lca(i,j)]<=mid)res=1;
			}
			if(res==0)flag=0;
		}
		return flag;
	}
	for(ll v:a[u]){
		if(v==fa)continue;
		if(fl[u]==0){
			fl[v]=1;
			if(dfs(cnt+1,tot+1,v,mid,u))return 1;
			fl[v]=0;
		}else{
			fl[v]=1;
			if(dfs(cnt,tot+1,v,mid,u))return 1;
			fl[v]=0;
		}
		if(dfs(cnt,tot,v,mid,u))return 1;
	}
	return 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		memset(f,0,sizeof f);
		memset(dep,0,sizeof dep);
		memset(fl,0,sizeof fl);
		dep[1]=1;
		n=read(),k=read();
		for(int i=1;i<=n;i++)a[i].clear();
		for(int i=1,u,v;i<n;i++){
			u=read(),v=read();
			a[u].push_back(v);
			a[v].push_back(u);
		}
		ll l=1,r=2*n,ans=-1;
		dfs1(1,-1);
		while(l<=r){
			memset(fl,0,sizeof fl);
			ll mid=l+r>>1;
			if(dfs(0,0,1,mid,-1))ans=mid,r=mid-1;
			else l=mid+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

