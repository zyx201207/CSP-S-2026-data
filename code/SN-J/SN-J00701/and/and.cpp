//孟楚程  辅轮中学  SN-J00701 
#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=2e5+5;
int n,m,a[maxn],vis[maxn],ans;map<string,int>cnt;string xie;
void dfs1(int x,int gai,string nw){
	cnt[nw]++;if(gai==-1) return;
	if(x>>gai&1){dfs1(x,gai-1,nw+'0');dfs1(x,gai-1,nw+'1');}else dfs1(x,gai-1,nw+'0');
}
void dfs(int x,string nw){//表示该看第x位 
	if(x==-1){xie=nw;return;}
	string mcc=nw;mcc+='1';string xbr=nw;xbr+='0';
	if(cnt[mcc]>=m) dfs(x-1,mcc);
	else dfs(x-1,xbr);
}
void dfs2(int x,int nw){//已经选了x个数 
	if(x==m){ans=max(ans,nw);return;}
	for(int i=1;i<=n;i++) if(!vis[i]){
		vis[i]=1;dfs2(x+1,(nw & a[i]));vis[i]=0;
	}
}
signed main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	if(n<=20){
		for(int i=1;i<=n;i++) cin>>a[i];
		dfs2(0,(1<<30)-1);cout<<ans<<'\n';
	}else if(n<=2000&&m==1){
		for(int i=1;i<=n;i++){cin>>a[i];ans=max(ans,a[i]);}
		cout<<ans<<'\n';
	}else if(n<=2000&&m==n){
		for(int i=1;i<=n;i++) cin>>a[i];
		ans=(1<<30)-1;
for(int i=1;i<=n;i++){ans=ans&a[i];}cout<<ans<<'\n';
	}else if(n<=2000&&m==2){
		for(int i=1;i<=n;i++) cin>>a[i];
		dfs2(0,(1<<30)-1);cout<<ans<<'\n';
	}else if(n<=2000&&m==n-1){
		for(int i=1;i<=n;i++) cin>>a[i];
		dfs2(0,(1<<30)-1);cout<<ans<<'\n';
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];dfs1(a[i],30,"");
		}
		dfs(29,"0");int lala=1;
		for(int i=xie.size()-1;i>=0;i--){
			if(xie[i]=='1') ans+=lala;lala=lala<<1;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
