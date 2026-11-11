#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int c,n,m,d,q;
long long a[N],ans,sum,cnt,idx;
int e[N],h[N],w[N],ne[N],vis[N];
void add(int x,int y,int v){
	ne[idx]=h[x],e[idx]=y,w[idx]=v,h[x]=idx++;
}
void dfs(int l,int r){
	if(vis[l]) return;
	if(l==r){
		ans=min(ans,sum);
		return;
	}
	if(sum>=ans) return;
	for(int i=h[l];i!=-1;i=ne[i]){
		sum+=w[i];
		vis[e[i]]=1;
		dfs(e[i],r);
		sum-=w[i];
		vis[e[i]]=0;
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	cnt=m+2;
	memset(h,-1,sizeof h);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int x,v;
			cin>>x>>v;
			add(x,cnt,v);
			add(cnt,x,v);
			cnt++;
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		long long ans=1e18+7,sum=0;
		dfs(l,r);
		cout<<ans+a[l]+a[r]<<endl;
	}
	return 0;
}
