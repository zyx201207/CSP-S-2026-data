#include<bits/stdc++.h>
using namespace std;
void file_init(){
#ifdef LOCAL
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
#else
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
#endif
	return;
}
void fast_read(){
#ifndef cin
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#endif
	return;
}
int n;
#define ll long long
ll m;
const int N=5e5+10;
ll a[N];
void input(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	return;
}
ll sum[N];
void init(){
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	return;
}
int ans;
void solve(){
	int now=1;
	for(int i=1;i<=n;i++){
		while(now<=i&&a[i]*(i-now+1)-(sum[i]-sum[now-1])>m){
			now++;
		}
		ans=max(ans,i-now+1);
	}
	return;
}
int main(){
	file_init();
	fast_read();
	input();
	init();
	solve();
	cout<<ans;
	return 0;
}
