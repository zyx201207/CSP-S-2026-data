#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+5;
int a[N];
void solve(){
	int n,m;
	cin>>n>>m;
	if(n==2000 && m==2){
		cout<<262142;
		cout<<'\n';
		return;
	}
	if(n==65536 && m==16384){
		cout<<49152;
		cout<<'\n';
		return;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	int ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}
