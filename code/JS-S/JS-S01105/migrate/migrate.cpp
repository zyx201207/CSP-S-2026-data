#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,T;
int n,d;
int a[N];
int minn[N];
int cnt[N];
void solve(int x,int step){
	if(x>n)return ;
	if(step<minn[x]){
		minn[x]=step;
		cnt[x]=0;
	}
	if(step==minn[x])cnt[x]++;
	for(int i=x+1;i<=n;i++){
		if(a[x]+d>=a[i]){
			solve(i,step+1);
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in"."r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)minn[j]=1e18;
			for(int j=1;j<=n;j++)cnt[j]=0;
			solve(i,0);
			for(int j=1;j<=n;j++)if(cnt[j]==2)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
freopen("migrate.in"."r",stdin);
freopen("migrate.out","w",stdout);
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

