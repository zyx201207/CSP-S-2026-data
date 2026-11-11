#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int m,q,c,f[N],tt,d,dp[N],cnt[N],dis[N],k,nxt[N],ans,num[N],op,n;
vector<int>G[N];
vector<char>kl;
void dfs_(int u,int fa){
	
	for(auto t:G[u]){
		if(t==fa)continue;
		if(cnt[t]&&!cnt[u])ans++;
		dfs_(t,u); 
	}
}
void dfs(int u,int cnt_){
	if(u>n&&cnt_==k){
		ans=0;
		queue<int>q;
		for(int i=1;i<=n;++i)cnt[i]=dis[i]=0,num[i]=1e16;
		int lst=0;
		for(auto t:kl){
			lst++;
			if(t=='1'){
				cnt[lst]=dis[lst]=1;
				num[lst]=0;
				q.push(lst);
			}
			
		}
		if(cnt[1])ans++;
		dfs_(1,0);
		if(ans<=2){
			int maxn=0;
			while(!q.empty()){
				int u=q.front();
				maxn=max(maxn,num[u]);
				q.pop();
				for(auto t:G[u]){
					if(num[u]+1<num[t]){
						num[t]=num[u]+1;
						q.push(t);
					}
				}
//				cout<<u<<'\n';
			}
			op=min(op,maxn);
			
		}
		return ;
	}
	if(u>n){
		return ;
	}
	kl.push_back('1');
	if(cnt_<k)dfs(u+1,cnt_+1);
	kl.pop_back();
	kl.push_back('0');
	dfs(u+1,cnt_);
	kl.pop_back();
}
signed main(){
	freopen("hub.in","r",stdin);//正解：首先考虑连通块个数限制有什么作用，所以先抛弃它，然后疯狂模样例和联想直径性质，不难想到用直径中心做（唯一性），然后就能发现其实在选完原树的中心时，给中心及其相连的边去掉，再这样递归下去就能出答案，时间复杂度和归并一样，然后不难发现加上限制以后其实是不能只选中心，而到中心的路径上也要选就行了 
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>tt;
	while(tt--){
		cin>>n>>k;
		for(int i=1;i<=n;++i)G[i].clear();
		for(int i=1;i<n;++i){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		op=n;
		dfs(1,0);
		cout<<op<<'\n';
	}
	return 0;
}
