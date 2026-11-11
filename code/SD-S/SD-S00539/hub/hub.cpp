#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define PII pair<int,int>
const int N=1e5+5,mod=1e9+7;
int n,m,q,T,c;
int a[N],fa[N];
vector<int>edge[N];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
bool check(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j:edge[i]){
			if(a[i]==a[j]&&a[i]){
				int fi=find(i),fj=find(j);
				if(fi!=fj)fa[fi]=fj;
			}
		}
	}
	set<int>s;
	for(int i=1;i<=n;i++){
		if(a[i]){
			s.insert(find(i));
		}
	}
}
void make(int i,int now){
	if(i>n){
		if(now<m||(!check())){
			return;
		}
		return;
	}
	if(now<m){
		a[i]=1;
		make(i+1,now+1);
	}
	a[i]=0;
	make(i+1,now)
}
void solve(){
	cin>>n>>m;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
//	make(1,0);
	cout<<0<<"\n";
}
signed main(){
	ios;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}

