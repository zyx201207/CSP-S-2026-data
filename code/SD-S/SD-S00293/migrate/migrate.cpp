#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d;
const int N = 2e6+5;
int a[N];
int ans = 0,minn;
void dfs(int st,int ed,int sum){
	if(st == ed){
		if(sum < minn){
			ans = 1;
			minn = sum;
		}
		else if(sum == minn)ans++;
		return ;
	}
	for(int i=st+1;i<=n;i++){
		if(abs(a[i]-a[st])<=d){
			dfs(i,ed,sum+1);
		}
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>=25){
		cout<<0<<"\n";
		return ;
	}
	int cnt = 0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans = 0;
			minn = LLONG_MAX;
			dfs(i,j,0);
			if(ans == 2)cnt++;
		}
	}
	cout<<cnt<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6
//
