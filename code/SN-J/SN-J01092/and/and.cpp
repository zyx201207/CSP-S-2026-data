#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=6e6+5;
int n,C;
int a[N];
int trie[M][2],tot,cnt[M];
bool Bit[35];
void insert(int val){
	int u=0;
	for(int i=30;i>=0;i--){
		bool id=bool(val&(1<<i));
		//cout<<id<<' ';
		if(!trie[u][id]){
			trie[u][id]=++tot;
		}
		u=trie[u][id];
		cnt[u]++;
	}
}
void dfs(int u,int dep,int m){
	//cout<<u<<' '<<dep<<' '<<m<<'\n';
	if(dep<0||m==0){
		return;
	}
	if(cnt[trie[u][1]]>=m){
		Bit[dep]&=1;
		if(trie[u][1]) dfs(trie[u][1],dep-1,m);
	}else{
		Bit[dep]&=0;
		if(trie[u][1]) dfs(trie[u][1],dep-1,cnt[trie[u][1]]);
		if(trie[u][0]) dfs(trie[u][0],dep-1,m-cnt[trie[u][1]]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>C;
//	cout<<n<<' '<<C<<'\n';
	for(int i=1;i<=n;i++){
		cin>>a[i];
		insert(a[i]);
		//cout<<'\n';
	}
//	cout<<"ok"<<'\n';
	for(int i=30;i>=0;i--){
		Bit[i]=1;
	}
//	for(int i=1;i<=tot;i++){
//		cout<<i<<' '<<cnt[i]<<'\n';
//	}
	dfs(0,30,C);
	int ans=0;
	for(int i=30;i>=0;i--){
		if(Bit[i]){
			ans+=(1<<i); 
		}
	}
	cout<<ans;
	return 0;
}
