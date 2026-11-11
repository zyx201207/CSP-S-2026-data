#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int n,d,a[N],to[N],dp[N][7],ans;
struct node{
	int x,y,z;
	void fill(int t){
		if(z<=t) z=0;
		if(y<=t) y=0;
		if(x<=t) x=0;
	}
};
node merge(node x,node y){
	node z=x;
	if(y.x>=z.x) z.z=z.y,z.y=z.x,z.x=y.x;
	else if(y.x>=z.y) z.z=z.y,z.y=y.x;
	else z.z=max(z.z,y.x);
	if(y.y>=z.y) z.z=z.y,z.y=y.y;
	else z.z=max(z.z,y.y);
	z.z=max(z.z,y.z);
	return z;
}
int get(node x){
	if(x.x==0) return -1;
	if(x.y==0) return 0;
	if(x.z==0){
		if(x.y==x.x) return 2;
		return 1;
	}
	if(x.y==x.x&&x.z==x.x) return 6;
	if(x.y==x.z) return 4;
	if(x.y==x.x) return 5;
	return 3;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;i++) for(int j=0;j<7;j++) dp[i][j]=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1,j=1;i<=n;i++){
			while(j<n&&a[j+1]-a[i]<=d) j++;
			to[i]=j;
		}
		for(int i=1;i<n;i++){
			dp[i][0]++;
			node w;
			if(dp[i][0]){
				w={to[i],to[i]-1,to[i]-2};
				w.fill(i);
				int x=get(w);
				if(x>=0) dp[w.x][x]+=dp[i][0];
			}
			if(dp[i][1]){
				w=merge({to[i],to[i]-1,to[i]-2},{to[i-1],to[i-1]-1,to[i-1]-2});
				w.fill(i);
				int x=get(w);
				if(x>=0) dp[w.x][x]+=dp[i][1];
				if(to[i-1]>i) ans+=(to[i-1]-i)*dp[i][1];
			}
			if(dp[i][2]){
				w={to[i],to[i],to[i]-1};
				w.fill(i);
				int x=get(w);
				if(x>=0) dp[w.x][x]+=dp[i][2];
				if(to[i]>i) ans+=(to[i]-i)*dp[i][2];
			}
			if(dp[i][3]){
				w=merge(merge({to[i],to[i]-1,to[i]-2},{to[i-1],to[i-1]-1,to[i-1]-2}),{to[i-2],to[i-2]-1,to[i-2]-2});
				w.fill(i);
				int x=get(w);
				if(x>=0) dp[w.x][x]+=dp[i][3];
				if(to[i-2]>i) ans+=(to[i-1]-to[i-2])*dp[i][3];
				else if(to[i-1]>i) ans+=(to[i-1]-i)*dp[i][3];
			}
			if(dp[i][4]){
				w=merge({to[i],to[i]-1,to[i]-2},{to[i-1],to[i-1],to[i-1]-1});
				w.fill(i);
				int x=get(w);
				if(x>=0) dp[w.x][x]+=dp[i][4];
			}
			if(dp[i][5]){
				w=merge({to[i],to[i],to[i]-1},{to[i-1],to[i-1]-1,to[i-1]-2});
				w.fill(i);
				int x=get(w);
				if(x>=0) dp[w.x][x]+=dp[i][5];
				if(to[i-1]>i) ans+=(to[i]-to[i-1])*dp[i][5];
				else if(to[i]>i) ans+=(to[i]-i)*dp[i][5];
			}
			if(dp[i][6]){
				w={to[i],to[i],to[i]};
				w.fill(i);
				int x=get(w);
				if(x>=0) dp[w.x][x]+=dp[i][6];
			}
	//		cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<" "<<dp[i][4]<<" "<<dp[i][5]<<" "<<dp[i][6]<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}
