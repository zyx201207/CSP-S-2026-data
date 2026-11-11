#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1005;
int n,K;
vector<int> v[N];
//int dp[N][2][2];
int dep[N];
int MID;
int dfn[N],siz[N],tim=0;
vector<int> a[N];
void dfs(int x,int fa){
	dep[x]=1;
	siz[x]=1;
	dfn[x]=++tim;
	for(int t:v[x]){
		if(t==fa) continue;
		dfs(t,x);
		siz[x]+=siz[t];
		dep[x]=max(dep[x],dep[t]+1);
	}
}
int LCA(int x,int y){
	
}
bool check(int mid){
	MID=mid;
	int l=1,r=1;
	for(int t:v[1]){
		while(r+1<a[mid].size()&&dfn[a[mid][r+1]]<dfn[t]+siz[t]) r++;
		
	}
}
void solve(){
	cin>>n>>K;
	tim=0;
	for(int i=1;i<=n;i++) a[i].clear();
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,1);
	for(int i=1;i<=n;i++){
		sort(a[i].begin(),a[i].end(),[&](const int &x,const int &y){
			return dfn[x]<dfn[y];
		});
	}
	sort(v[1].begin(),v[1].end(),,[&](const int &x,const int &y){
			return dfn[x]<dfn[y];
		});
	int l=0,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int CC,T;
	cin>>CC>>T;
	while(T--) solve();
	return 0;
}
