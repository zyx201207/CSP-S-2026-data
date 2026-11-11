#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],t[N],nxt[N],ans[N],ind[N],zx[N],cnt[N],sum[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	//LL!
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		if(!t[a[i]]) t[a[i]]=i,zx[i]=i;
		else{
			zx[i]=zx[t[a[i]]];
		}
		cnt[zx[i]]++;
	}
	for(int i=1;i<n;i++)
		if(zx[i]==i) nxt[i]=zx[i+1],ind[zx[i+1]]++;
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(zx[i]==i&&!ind[i]) q.push(i);
	while(q.size()){
		int d=q.front();q.pop();
		sum[d]+=cnt[d];
		if(nxt[d]){
			ind[nxt[d]]--;sum[nxt[d]]+=sum[d];
			if(!ind[nxt[d]]) q.push(nxt[d]);
		}
	}
	for(int i=1;i<=n;i++)
		if(zx[i]==i) ans[a[i]]=sum[i];
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
