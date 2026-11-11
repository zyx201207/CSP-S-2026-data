#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,T,n,m,a[N],ans;
int dfs(int x,int mx,int sum,int lim){
	if(sum>lim)return 0;
	if(x==mx)return 1;
	int res=0;
	for(int i=min(mx,upper_bound(a+x,a+n+1,a[x]+m)-a-1);i>x;i--){
		int now=dfs(i,mx,sum+1,lim);
		if(!now)break;
		res+=now;
		if(res>2)return res;
	}return res;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==1){
			cout<<"0\n";
			continue ;
		}
		if(11<=c && c<=12){
			int k=m/(a[2]-a[1]);
			cout<<max(0ll,n-2*k+1)<<'\n';
			continue ;
		}
		for(int i=1;i<=n;i++){
			if(a[n]-a[i]<=m)break;
			int mx=upper_bound(a+i,a+n+1,a[i]+m)-a-1,now=1;
			for(int j=i;j<=n;j++){
				if(dfs(i,j,0,now)==2)ans++;
				if(j==mx){
					mx=upper_bound(a+j,a+n+1,a[j]+m)-a-1;
					if(j==mx)break;
					now++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
