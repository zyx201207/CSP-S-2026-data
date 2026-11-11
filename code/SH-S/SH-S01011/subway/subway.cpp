#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pll pair<int,int> 
const int N=5e5+10,M=510;
int c,n,m,d,q,w[N],a[M][M],t[M][M],ans,siz[N];
void dfs(int u,int e,int sum,int xid,int lstid){
	int flag=0,id=0;
//	cout<<u<<" "<<sum<<" "<<xid<<"\n";
	if(u==e) {
		for(int j=1;j<=siz[xid];j++){
			if(a[xid][j]==u){
				id=j;
				break;
			}
		}
		ans=min(ans,sum+t[xid][id]);
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=siz[i];j++){
			if(a[i][j]==u){
				flag=1;
				id=j;
			}
		}
		if(flag==1) {
			for(int j=id+1;j<=siz[i];j++) {
				if(xid==i) dfs(a[i][j],e,sum,i,j);
				else dfs(a[i][j],e,sum+t[i][id]+t[xid][lstid],i,j);
			}
		}
		flag=0,id=0;
	} 
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		siz[i]=k;
		for(int j=1;j<=k;j++) cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		int s,e;
		ans=1e18+10;
		cin>>s>>e;
		dfs(s,e,w[s]+w[e],0,0);
//		cout<<a[2][3]<<"\n";
		cout<<ans<<"\n";
	}
	return 0;
}
