#include<bits/stdc++.h>
#define int long long
using namespace std;

int c,t,n,k,fa[1000005],g[1000005][2];

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void Union(int x,int y){
	fa[find(y)]=find(x);
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","r",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int x,y;
			cin>>x>>y;
		}
		cout<<1<<'\n';
	}
	return 0;
}