#include<bits/stdc++.h>
#include<cassert>
const int N=1e6+10;
using namespace std;
int pa[N],lim,n,k,id[N];
vector<int>g[N];
struct jg{
	int num,d1,d2;
}dp[N],dp1[N];
int pre[N],suf[N],rk[N],tmp[N],p2[N],s2[N],cd;
void init(int u,int fa){
	id[++cd]=u,pa[u]=fa;
	for(int v:g[u]){
		if(v^fa) init(v,u);
	}
}
bool chk(int x){
	lim=x;
	for(int __=n;__;__--){
		int u=id[__],fa=pa[u],nb=0,len=0;
		jg _;
		dp[u]={0,0,0};
		for(int v:g[u]){
			if(v^fa){
				if(dp[v].d2<lim) len=max(len,dp[v].d2+1);
				else _=dp[v];
				dp[u].d2=max(dp[u].d2,dp[v].d2+1),nb+=(dp[v].d2>=lim);
			}
		}
		if(dp[u].d2<=lim) continue;
		if(nb>=2){
			dp[u].num=1,dp[u].d1=0;
			for(int v:g[u]){
				if((v^fa)&&dp[v].d2>=lim) dp[u].num+=(dp[v].num?dp[v].num+dp[v].d1:1);
			}
			continue;
		}
		if(_.d2>=lim){
			if(!_.num){
				if(len<lim) dp[u].num=1,dp[u].d1=1;
				else dp[u].num=2,dp[u].d1=0;
			}
			else{
				dp[u].num=_.num,dp[u].d1=_.d1+1;
				if(dp[u].d1+len>lim) dp[u].num+=dp[u].d1+len-lim,dp[u].d1=lim-len;
			}
		}
	}
	for(int __=1;__<=n;__++){
		int u=id[__],fa=pa[u];
		if(u>1){
			if(max(1,dp[u].num)+max(1,dp1[u].num)<=k) return 1;
		}
		int nb=0,cc=0,sum=0;
		int u1=-1,u2=-1;
		jg j1,j2;
		if(u>1){
			nb=(dp1[u].d2>=lim);
			if(dp1[u].d2>=lim) sum+=(dp1[u].num?dp1[u].num+dp1[u].d1:1);
		}
		for(int v:g[u]){
			if(v^fa){
				rk[v]=++cc,tmp[cc]=v,nb+=(dp[v].d2>=lim);
				if(dp[v].d2>=lim){
					sum+=(dp[v].num?dp[v].num+dp[v].d1:1);
					if(u1==-1) u1=v,j1=dp[v];
					else if(u2==-1) u2=v,j2=dp[v];
				}
			}
		}
		pre[0]=suf[cc+1]=p2[0]=s2[cc+1]=0;
		for(int i=1;i<=cc;i++){
			pre[i]=max(pre[i-1],dp[tmp[i]].d2+1);
			p2[i]=p2[i-1];
			if(dp[tmp[i]].d2<lim) p2[i]=max(p2[i],dp[tmp[i]].d2+1);
		}
		for(int i=cc;i;i--){
			suf[i]=max(suf[i+1],dp[tmp[i]].d2+1);
			s2[i]=s2[i+1];
			if(dp[tmp[i]].d2<lim) s2[i]=max(s2[i],dp[tmp[i]].d2+1);
		}
		for(int v:g[u]){
			if(v==fa) continue;
			dp1[v]={0,0,0};
			if(u>1) dp1[v].d2=max(dp1[v].d2,dp1[u].d2+1);
			dp1[v].d2=max({dp1[v].d2,pre[rk[v]-1],suf[rk[v]+1]});
			if(dp1[v].d2<=lim) continue;
			if(nb-(dp[v].d2>=lim)>=2){
				dp1[v].d1=0;
				dp1[v].num=1+sum;
				if(dp[v].d2>=lim) dp1[v].num-=(dp[v].num?dp[v].num+dp[v].d1:1);
				continue;
			}
			int len=max({p2[rk[v]-1],s2[rk[v]+1]});
			if(u>1&&dp1[u].d2<lim) len=max(len,dp1[u].d2+1);
			int num=-1,d1=-1;
			if((~u1)&&u1!=v) num=j1.num,d1=j1.d1;
			if((~u2)&&u2!=v) num=j2.num,d1=j2.d1;
			if(num==-1) num=dp1[u].num,d1=dp1[u].d1;
			if(!num){
				if(len<lim) dp1[v].num=1,dp1[v].d1=1;
				else dp1[v].num=2,dp1[v].d1=0;
			}else{
				dp1[v].num=num,dp1[v].d1=d1+1;
				if(dp1[v].d1+len>lim) dp1[v].num+=dp1[v].d1+len-lim,dp1[v].d1=lim-len;
			}
		}
	}
	return 0;
}
int wa=99420;
void solve(int tc){
	cin>>n>>k,cd=0;
	if(tc==wa) cerr<<n<<" "<<k<<"\n";
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		if(tc==wa) cerr<<u<<" "<<v<<"\n";
		g[u].push_back(v),g[v].push_back(u);
	}
	init(1,0);
	if(n==k){cout<<"0\n";return;}
	int l=1,r=n/2;
	while(l<r){
		int mid=(l+r)>>1;
		if(chk(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(0);
	int cid,T;cin>>cid>>T;int tc=0;//clock_t st=clock();
	while(T--) solve(++tc);
	//cerr<<1.0*(clock()-st)/CLOCKS_PER_SEC<<"\n";
	return 0;
}