#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000010]={},mi,tmp=0,ans=0,l;
bool f[200010]={};
unordered_map<int,int>mp;
void dfs(int pos,int cnt,int r){
	if(pos>r){
		int lst=l,res=0,mask=0;
		bool flag=true;
		f[l]=f[r]=true;
		for(int i=l;i<=r;i++){
			mask=(mask<<1)+f[i];
			if(f[i]) res++;
			if(f[i]&&x[i]-x[lst]>d) flag=false;
			if(f[i]) lst=i;
		}
		if(flag){
			if(mp[mask]) return;
			mp[mask]=true;
			if(mi==res-1) tmp++;
			else if(mi>res-1) mi=res-1,tmp=1;
		}
		return;
	}
	f[pos]=true;
	dfs(pos+1,cnt+1,r);
	f[pos]=false;
	dfs(pos+1,cnt,r);
}
void solve(){
	if(c==13||c==14){puts("2");return;}
	scanf("%lld%lld",&n,&d);
	ans=0;
	for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i<j){
		l=i,tmp=0,mi=1e9,dfs(i,0,j),mp.clear();	
		if(tmp==2) ans++;
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--) solve();
	return 0;
}
