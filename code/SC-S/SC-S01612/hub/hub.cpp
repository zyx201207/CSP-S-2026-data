#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,w,dep[N],aver;
mt19937 rng(time(0));
vector<int> tr[N];
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	aver=max(aver,dep[x]);
	for(auto son:tr[x]){
		if(son!=f) dfs(son,x);
	}
}
void solve(){
	cin>>n>>w;
	for(int i=1;i<=n;i++){
		tr[i].clear();
	}
	aver=0;
	for(int i=1;i<=n-1;i++){
		int a,b;cin>>a>>b;
		tr[a].emplace_back(b);
		tr[b].emplace_back(a);
	}
	dfs(1,0);
	cout<<rng()%(aver/2-w/2);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}

	return 0;
}