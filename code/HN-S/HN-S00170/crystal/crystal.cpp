#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int N=1e6+5;
int n,m;
int a[N];
int sum[N];
bool check(int mid){
	for(int i=mid;i<=n;i++){
		int tmp=mid*a[i]-(sum[i]-sum[i-mid]);
		if(tmp<=m) return 1;
	}
	return 0;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=-1,r=n+1;
	while(l+1<r){
		int mid=l+r>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<l<<endl;
	return ;
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T=1; //cin>>T;
	while(T--) solve();
	return 0;
}  
/*
 5 8
-3 -1 2 2 7
*/
