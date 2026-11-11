#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000010
#define M 22
int c,t,n,d,x[N],v[N][3],up[N][M],ans;
inline int findr(int x,int y){
	for(int i=21;i>=0;i--){
		if(up[x][i]!=up[y][i]){
			x=up[x][i];
			y=up[y][i];
		}
	}
	if(up[y][0]==y){
		return n+1;
	}
	return up[y][0];
}
inline void change(int i,int p){
	if(p>=v[i][0]){
		v[i][2]=v[i][1];
		v[i][1]=v[i][0];
		v[i][0]=p;
	}
	else if(p>=v[i][1]){
		v[i][2]=v[i][1];
		v[i][1]=p;
	}
	else if(p>=v[i][2]){
		v[i][2]=p;
	}
	return ;
}
inline int check(int i,int r){
	if(up[i][21]<=r-1){
		return 0;
	}
	v[0][0]=i;
	v[0][1]=v[0][2]=0;
	while(v[0][0]<=r-1){
		int p1=v[0][0],p2=v[0][1],p3=v[0][2];
		v[0][0]=v[0][1]=v[0][2]=1;
		change(0,up[p1][0]);
		if(up[p1][0]<=r-1){
			change(0,up[p1][0]-1);
			change(0,up[p1][0]-2);
		}
		change(0,up[p2][0]);
		if(up[p2][0]<=r-1){
			change(0,up[p2][0]-1);
		}
		change(0,up[p3][0]);
	}
	return (v[0][1]>=r)&&(v[0][2]<=r-1);
}
inline void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int now=n;
	for(int i=n;i>=1;i--){
		while(x[now]-x[i]>=d+1){
			now--;
		}
		up[i][0]=now;
	}
	for(int i=1;i<=21;i++){
		for(int j=1;j<=n;j++){
			up[j][i]=up[up[j][i-1]][i-1];
		}
	}//cout<<check(2,3)<<'\n';exit(0);
	v[n][0]=n+1;
	v[n][1]=n;
	for(int i=n-1;i>=1;i--){
		for(int j=i;j<=n;j++){
			ans+=check(i,j);
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
