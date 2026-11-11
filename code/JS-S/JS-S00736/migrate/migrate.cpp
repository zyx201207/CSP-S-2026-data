#include<bits/stdc++.h>
using namespace std;
// bool st;
const int MAXN=2e6+5;
int n;
long long m;
long long a[MAXN];
int lst[MAXN],nxt[MAXN];
vector<int> g[MAXN];
int stk[MAXN],top;
int ct0[MAXN],ct1[MAXN];
int cnt[3];
long long ans;
bool vis[MAXN];
int minn[MAXN],maxn[MAXN];
void dfs(int x){
	vis[x]=1;
	int c0=cnt[0],c1=cnt[1],c2=cnt[2];
	int nn=nxt[nxt[x]];
	if(nn<=n){
		cnt[0]+=ct0[nxt[x]];
	}
	ans+=cnt[1]+cnt[2]+(nxt[x]<=n?ct1[nxt[x]]:0);
	// cout<<x<<" "<<cnt[1]+cnt[2]+(nxt[x]<=n?ct1[nxt[x]]:0)<<" "<<cnt[1]<<" "<<cnt[0]<<"\n";
	if(cnt[2]&&lst[nxt[x]-1]!=x){
		cnt[2]=0;
	}else{
		cnt[1]+=cnt[2];
		cnt[2]=0;
	}
	if(nxt[x]<=n){
		if(lst[nxt[x]]==x-1){
			// cout<<"::"<<x<<"\n";
			cnt[2]=cnt[0],cnt[0]=cnt[1]=0;
		}else if(lst[nxt[x]]<x-1){
			cnt[0]=cnt[1]=0;
		}
		if(nn<=n){
			if(lst[nxt[x]-1]==x){
				// assert(!ct1[nxt[x]]);
				// cout<<":::"<<x<<"\n";
				cnt[1]+=ct1[nxt[x]];
			}
		}
	}
	for(auto to:g[x]){
		if(to>=x){
			continue;
		}
		dfs(to);
	}
	cnt[0]=c0,cnt[1]=c1,cnt[2]=c2;
}
void solve(){
	scanf("%d%lld",&n,&m);
	int pos=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		while(pos<=i&&a[i]-a[pos]>m){
			pos++;
		}
		lst[i]=pos;
		g[i].clear();
	}
	pos=n;
	lst[1]=0,nxt[n+1]=nxt[n]=n+1;
	for(int i=n-1;i>=1;i--){
		while(pos>=i&&a[pos]-a[i]>m){
			pos--;
		}
		nxt[i]=pos;
		g[nxt[i]].push_back(i);
		ct0[i]=ct1[i]=0;
	}
	for(int i=0;i<=n+1;i++){
		minn[i]=n+1,maxn[i]=0;
		vis[i]=0;
	}
	ct0[n]=ct1[n]=ct0[n+1]=ct1[n+1]=0;
	for(int i=n;i>=1;i--){
		minn[lst[i]]=min(minn[lst[i]],i);
		maxn[lst[i]]=max(maxn[lst[i]],i);
	}
	for(int i=1;i<n;i++){
		ct0[i]=max(0,min(nxt[i],maxn[i])-max(i+1,minn[i])+1);
		ct1[i]=max(0,min(nxt[i],maxn[i-1])-max(i+1,minn[i-1])+1);
	}
	ans=0;
	for(int i=n;i>=1;i--){
		if(!vis[i]){
			dfs(i);
		}
	}
	printf("%lld\n",ans);
}
// bool ed;
signed main(){
	// cerr<<(&ed-&st)/1048576.0;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	scanf("%d",&t);
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}