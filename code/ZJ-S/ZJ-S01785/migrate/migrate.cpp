#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,N1=5e3+5,INF=1e18;
int c,t,n,d,x[N],dis[N1][N1],ans,to_ng[N];
vector<int> g[N1];
void dfs(int l,int r,int step){
	if(l==r){
		to_ng[step]++;
		return;
	}
	for(int i=l+1;i<=r;i++){
		if(x[i]-x[l]<=d) dfs(i,r,step+1);
	}
}
int SpFA(){
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int flag=0;
			if(x[j]-x[i]<=d) continue;
			for(int k=i;k<j;k++) if(x[k+1]-x[k]>d) flag=1;
			if(flag) break;
			memset(to_ng,0,sizeof(to_ng));
			dfs(i,j,0);
			for(int k=1;k<=(j-i+1);k++) if(to_ng[k]==2){
//				cout<<i<<" "<<j<<" "<<k<<"\n";
				ans++;
				break;
			}
		}
	}
	return ans;
}
void work1(){
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		cout<<SpFA()<<"\n";
	}
}
void work2(){
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(d<x[2]-x[1]) cout<<0<<"\n";
		else cout<<max(n-2*d+1,0ll)<<"\n";
	}
}
signed main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=10){
		work1();return 0;
	}
//	work2();
	if(c==11||c==12){
		work2();return 0;
	}
	return 0;
}
