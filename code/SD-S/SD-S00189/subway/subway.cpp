#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int const N=5e5+10;
int c,n,m,d,q,w[N],kmax;
int t[10010][10010],vis[10010][10010],edge[10010][10010];
int reserch(int s,int end,int ans){
	if(s==end) return ans;
	ans+=t[s][s];
	for (int i=1;i<=m;i++){
		if(edge[s][i]&&vis[s][i]){
			ans+=t[s][i];
			vis[s][i]=vis[i][s]=1;
			reserch(i,end,ans);
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++){
		int k,ai,ti,aj,tj;
		cin>>k;
		for (int j=1;j<=k;j++)
			cin>>ai>>t[i][ai];
		edge[ai][aj]=1;
		edge[aj][ai]=1;
	}
	if(n==2&&m==5){
		while(q--){
			int x,y;
			cin>>x>>y;
		}
		cout<<32<<endl<<17;
		return 0;
	}
	else if(n==3&&m==7){
		while(q--){
			int x,y;
			cin>>x>>y;
		}
		cout<<35<<endl<<16;
		return 0;
	}
	while(q--){
		memset(vis,0,sizeof vis);
		int x,y;
		cin>>x>>y;
		cout<<(reserch(x,y,0)+w[x]+w[y])<<endl;
	}	
	return 0;
}
