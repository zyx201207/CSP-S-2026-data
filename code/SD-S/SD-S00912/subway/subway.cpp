#include<bits/stdc++.h>
using namespace std;
long long m,w[500006],c,n,d,q,ans;
vector<long long> a[501],t[501];
struct SS{
	long long v,id;
};
vector<SS> to[500006];
void dfs(long long now,long long ed,long long sum,long long id){
	int ok=0;
	for(int i=0;i<a[id].size();i++){
		if(a[id][i]==now){
			ok=1;
			break;
		}
	}
	if(ok==0) return;
	if(now==ed){
		ans=min(ans,sum+w[ed]);
		return;
	}
	for(SS nxt:to[now]){
		if(nxt.id!=id){
			dfs(nxt.v,ed,sum+t[id][now]+t[nxt.id][now],nxt.id);
		}else{
			dfs(nxt.v,ed,sum,id);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
			if(j>=2){
				to[a[i][j-2]].push_back(SS{x,i});
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ans=1e18;
		for(int j=1;j<=n;j++){
			dfs(x,y,w[x],j);
		}
		cout<<ans<<endl;
	}
	return 0;
}
