#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+5;
vector<int>e[500005];
int a[500005];
int last[N];
int ta[500005];
int tata[500005];
int ans[N];
inline void pushta(int x,int k){
	tata[x]+=k;
	ta[x]+=k;
}
inline void down(int x){
	if(e[x].empty())return;
	if(tata[x]==0)return;
	for(auto i:e[x]){
//		if(i==8)cout<<"!!!";
		if(i!=x+1)ta[x]=0;
		pushta(i,tata[x]);
	}
	tata[x]=0;
}
inline void dfs(int u){
	if(ta[u]){
		pushta(u,1);
		return;
	}
	ta[u]=1;
	for(auto i:e[u]){
		if(i!=u+1)ta[u]=0;
		dfs(i);
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		last[a[i]]=i;
	}
	for(int i=1;i<n;i++){
		if(last[a[i]]!=i)e[i].push_back(last[a[i]]);
		else e[i].push_back(i+1);
	}
	//cout<<e[8][0]<<"\n\n";
	for(int i=1;i<=n;i++){
		dfs(i);
	}
	for(int i=1;i<=n;i++){
		if(i!=n&&e[i][0]!=i+1||a[i]==a[i+1])ta[i]=0;
		//cout<<ta[i]<<" ";
		ans[a[i]]+=ta[i];
		down(i);
	}
//	cout<<"\n";
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
