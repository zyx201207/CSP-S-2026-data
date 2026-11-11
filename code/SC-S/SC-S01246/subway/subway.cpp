#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,d,w[500005],h[500505],sub[505][505];
int cntedge;
struct Edge{
	int from,to,nxt,val;
}edge[1001006];
void add(int from,int to,int val){
	edge[++cntedge]={from,to,h[from],val};
	h[from]=cntedge;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			sub[i][j]=1e17;
		}
		int k;cin>>k;
		for(++k;--k;){
			int ai,ti;cin>>ai>>ti;
			add(m+i,ai,ti);add(ai,m+i,ti);
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=h[i];j;j=edge[j].nxt){
			for(int k=h[i];k;k=edge[k].nxt){
				int to_j=edge[j].to-m,to_k=edge[k].to-m;
				sub[to_j][to_k]=sub[to_k][to_j]=min(sub[to_k][to_j],edge[j].val+edge[k].val);
			}
		}
	}
	for(int i=1;i<=n;++i){
		sub[i][i]=0;
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				sub[i][j]=min(sub[i][j],sub[i][k]+sub[k][j]);
			}
		}
	}
	for(++q;--q;){
		int x,y;cin>>x>>y;
		long long ans=1e17;
		for(int j=h[x];j;j=edge[j].nxt){
			for(int k=h[y];k;k=edge[k].nxt){
				int to_j=edge[j].to-m,to_k=edge[k].to-m;
				ans=min(ans,sub[to_j][to_k]+edge[j].val+edge[k].val);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}