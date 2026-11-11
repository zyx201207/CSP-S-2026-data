#include<bits/stdc++.h>
using namespace std;
/*====================*/
const int N=5e5+10;
const int M=3e5+10;
/*====================*/
const int INF=0x3f3f3f3f;
const int MOD=998244353;
/*====================*/
int n,m,a[N],nxt[M],lst[M],vis[N],ans[M];
int b[N][2];
vector<pair<int,int> > c;
void dfs(int x){
	if(x>n)return;
	c.push_back({x,a[x]});
	vis[x]=1;
	if(b[x][0]==-1)return;
	if(b[x][1]!=-1){
		dfs(b[x][1]);
	}else dfs(b[x][0]);
}
map<int,int> mp;
int e[N],visss[N];
/*====================*/
void Solve(){
	memset(b,-1,sizeof b);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(!lst[a[i]])lst[a[i]]=i;
		else nxt[lst[a[i]]]=i,lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(i!=n)b[i][0]=i+1;
		if(nxt[i]!=0){
			if(b[i][0]==-1)b[i][0]=nxt[i];
			else b[i][1]=nxt[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		c.clear();
		dfs(i);
		e[0]=(1-visss[c[0].first]);
		for(int j=1;j<c.size();j++)e[j]=e[j-1]+(1-visss[c[j].first]);
		for(int j=c.size()-1;j>=0;j--){
			if(mp.count(c[j].second))continue;
			mp[c[j].second]=1;
			ans[c[j].second]+=((j!=0?e[j-1]:0));
		}
		mp.clear();
		for(int j=c.size()-1;j>=0;j--)visss[c[j].first]=1;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]+1;
		if(i!=m)cout<<" ";
	}	
}
/*====================*/
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;//cin>>T;
	while(T--)Solve();
	return 0;
}

