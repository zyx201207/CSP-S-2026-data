#include <bits/stdc++.h>
using namespace std;
#define drintf(...) //fprintf(stderr,__VA_ARGS__),fflush(stderr)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
int rd(){
	int x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
const int maxn=1e6+10;
int c,T;
int n,k;
vector<pair<int,int> > mp[maxn];
bool vis[maxn];
int dep[maxn],hdep[maxn];
bool il[maxn];
void dfs0(int np,int fp){
	dep[np]=dep[fp]+1;
	hdep[np]=0;
	for(pair<int,int> pr:mp[np]){
		if(vis[pr.second])continue;
		int nt=pr.first;
		if(nt==fp)continue;
		dfs0(nt,np);
		hdep[np]=max(hdep[np],hdep[nt]+1);
	}
}
bool bus[maxn];
int dfs(int np,int fp,int lis){
	int d=0;
	for(pair<int,int> pr:mp[np]){
		if(pr.first==fp||vis[pr.second]||bus[pr.first])continue;
		d=max(d,dfs(pr.first,np,lis)+1);
	}
	if(d>=lis)bus[np]=1;
	return d;
}
void dfs_0(int np,int fp){
	il[np]=1;
	for(pair<int,int> pr:mp[np]){
		if(vis[pr.second])continue;
		int nt=pr.first;
		if(nt==fp)continue;
		dfs_0(nt,np);
	}
}
set<int> st;
bool check(int S){
	for(int i=1;i<=n;++i)bus[i]=il[i]=0;
	dfs_0(1,0);
	for(int i=1;i<=n;++i){
		dfs0(i,0);
//		drintf("%d:",i);
//		for(int i=1;i<=n;++i){
//			drintf("%d ",hdep[i]);
//		}
//		drintf("\n");
		int cnt=0;
		for(pair<int,int> pr:mp[i]){
			if(vis[pr.second])continue;
			if(hdep[pr.first]>=S-1)++cnt;
		}
		if(cnt>=2) bus[i]=1;
	}
	if(S==2){
		for(int i=1;i<=n;++i){
			drintf("%d ",bus[i]);
		}
		drintf("\n");
	}
	st.clear();
	bool f[2]={0,0};
	for(int i=1;i<=n;++i){
		if(bus[i]){
			f[il[i]]=1;
			for(pair<int,int> pr:mp[i]){
				if(vis[pr.second])continue;
				st.insert(pr.first);
			}
		}
	}
	
	int cnt=0;
	if(!f[0])++cnt;
	if(!f[1])++cnt;
	for(int i:st){
		if(f[il[i]])dfs(i,0,S);
	}

	
	for(int i=1;i<=n;++i){
		if(bus[i]){
			
			++cnt;
		}
	}
	return cnt<=k;
}
int solve(){
	int l=0,r=n,ans=n;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=rd();
	T=rd();
	while(T--){
		n=rd();
		k=rd();
		for(int i=1;i<=n;++i){
			mp[i].clear();
			vis[i]=0;
		}
		for(int i=1;i<n;++i){
			int u,v;
			u=rd();
			v=rd();
			mp[u].push_back({v,i});
			mp[v].push_back({u,i});
		}
		int ans=solve();
		for(int i=1;i<n;++i){
			vis[i]=1;
			ans=min(ans,solve());
			vis[i]=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/

