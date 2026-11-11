#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define PLL pair<LL,LL>
#define mp make_pair
#define mod ((LL)1e9+7)
#define inf ((LL)0x3f3f3f3f3f3f3f3f)
#define esp ((long double)1e-7)
#define len(x) ((LL)(x.size()))
inline LL mo(const LL x){return x-x/mod*mod;}
inline LL mo(const LL x,const LL p){return x-x/p*p;}
inline LL _mo(const LL x,const LL p){return mo(mo(x,p)+p,p);}
#define N ((LL)1e6+7)
LL c,n,k,ans;
vector<LL> ne[N];
LL maxx[N][3];
LL dfs1(LL u,LL fa){
	maxx[u][0]=maxx[u][1]=maxx[u][2]=0;
	for(auto v : ne[u]){
		if(v!=fa){
			maxx[u][0]=dfs1(v,u);
			sort(maxx[u],maxx[u]+3);
		}
	}
	return maxx[u][2]+1;
}
void dfs2(LL u,LL fa,LL len){
	for(auto v : ne[u]){
		if(v!=fa){
			dfs2(v,u,len+1);
		}
	}
	LL maxm[4]={maxx[u][1],maxx[u][2],maxx[1][1]+len,maxx[1][2]+len};
	sort(maxm,maxm+4);
	ans=min(ans,max(maxm[2],(maxm[3]-maxm[2])>>1));
}
inline void do_2(){
	dfs1(1,0);
	dfs2(1,0,0);
	cout<<ans<<'\n';
	return;
}
bool ch[N],vis[N];
LL maxn,cnt;
LL work(LL u,LL fa,LL len){
	LL minx=inf;
	if(ch[u]){
		len=minx=0;
	}
	for(auto v : ne[u]){
		if(v==fa){
			continue;
		}
		minx=min(minx,work(v,u,len+1));
	}
	maxn=max(maxn,min(len,minx));
	return minx+1;
}
void change(LL u){
	vis[u]=false;
	for(auto v : ne[u]){
		if(vis[v]){
			change(v);
		}
	}
}
inline bool check(){
	for(LL i=1,j=0;i<=n;++i){
		if(vis[i]){
			change(i);
			++j;
			if(j>2){
				return true;
			}
		}
	}
	return false;
}
void dfs(LL st){
	if(n-st+1<k-cnt){
		return;
	}
	if(st>n){
		for(LL i=1;i<=n;++i){
			vis[i]=ch[i];
		}
		if(check()){
			return;
		}
		maxn=-inf;
		work(1,0,inf);
		ans=min(ans,maxn);
		return;
	}
	if(cnt<k){
		ch[st]=true;
		++cnt;
		dfs(st+1);
		ch[st]=false;
		--cnt;
	}
	dfs(st+1);
}
inline void solve(){
	cin>>n>>k;
	for(LL i=1;i<=n;++i){
		ne[i].clear();
	}
	for(LL i=1;i<n;++i){
		LL u,v;
		cin>>u>>v;
		ne[u].push_back(v);
		ne[v].push_back(u);
	}
	ans=inf;
	if(c==11 || c==12){
		do_2();
		return;
	}
	if(n<=1000){
		dfs(1);
		cout<<ans<<'\n';
	}
	cout<<((n-1)/2+k-2)/3+1<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	LL T;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
