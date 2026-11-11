#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N=2e6+5;
int c,T,n;
ll d,x[N],ans[N],anss=0,dis[N],sz[N];
inline void init(){
	anss=0;
}
inline void dfs(int i,int l,int r,int flag){
//	cout<<l<<' '<<r<<endl;
	if(l>r) return ;
	if(r>n) return ;
	if(l==r){
		if(flag) anss++;
		int pos=upper_bound(x+r+2,x+n+1,x[r]+d)-x-1;
		if(!flag){
			dfs(i,l+1,pos,flag);
			return ;
		}else{
			dfs(i,l+1,pos,flag);
			return ;
		}
	}else{
		if(flag) anss+=r-l+1;
		int le=upper_bound(x+r+2,x+n+1,x[r-1]+d)-x-1;
		int ri=upper_bound(x+r+2,x+n+1,x[r]+d)-x;
		if(ri==n+1) ri=n;
		else ri-=2;
		cout<<l<<' '<<r<<' '<<le<<' '<<ri<<' '<<flag<<endl;
		if(le>ri) return ;
		if(!flag){
			dfs(i,r+1,le,1);
			return ;
		}else{
			dfs(i,ri,ri,0);
			return ;
		}
	}
}
void bfs(int xx,int stp){
//	cout<<xx<<' '<<stp<<endl;
//	cout<<dis[xx]<<endl;
	if(dis[xx]>stp){
		dis[xx]=stp;
		sz[xx]=1;
	}else if(dis[xx]==stp){
		sz[xx]++;
	}
	if(xx==n){
		return ;
	}
	for(int i=xx+1;i<=n;i++){
		if(x[i]-x[xx]<=d){
			bfs(i,stp+1);
		}else break;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		init();
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) dis[j]=0x3f3f3f3f,sz[j]=0;
			bfs(i,0);
			for(int j=i+1;j<=n;j++){
//				cout<<dis[j]<<' '<<sz[j]<<'\n';
				if(sz[j]==2) anss++;
			} 
		}
		cout<<anss<<'\n';
	}
	return 0;
}