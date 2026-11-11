#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
const int N=1e6+10;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int C,T;
int n,k;
int de[N],si[N],so[N];
vector<int> f[N];
void dfs(int u,int fa){
	so[u]=f[u].size();
	si[u]=1;
	for(int i=0;i<f[u].size();i++){
		int v=f[u][i];
		if(v==fa) continue;
		de[v]=de[u]+1;
		dfs(v,u);
		si[u]+=si[v];
	}
}
int dep(int tt,int u,int fa,int dee,int siz){
	if(siz>=k){
		return dee-de[tt];
	}
	for(int i=0;i<f[u].size();i++){
		int v=f[u][i];
		if(v==fa) continue;
		dep(tt,v,u,dee+1,siz+so[v]);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	C=read();T=read();
	while(T--){
		n=read();k=read();
		for(int i=1;i<=n;i++) f[i].clear();
		for(int i=1;i<=n-1;i++){
			int u=read(),v=read();
			f[u].push_back(v);
			f[v].push_back(u);
		}
		de[1]=1;
		dfs(1,0);
		int ans=-1;
		for(int i=1;i<=n;i++){
			if(so[i]>=k){
				ans=1;
				break;
			}
		}
		if(ans==-1){
			for(int i=n;i>=1;i--){
				if(si[i]>=k){
					ans=max(ans,dep(i,i,-1,0,so[i]));
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
