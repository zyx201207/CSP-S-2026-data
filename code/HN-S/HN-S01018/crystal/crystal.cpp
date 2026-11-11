#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N];
bool check(int t){
	int sum=0;
	for(int i=1;i<=t-1;i++) sum+=a[t]-a[i];
	if(sum<=m) return true;
	for(int i=t+1;i<=n;i++){
		sum+=(a[i]-a[i-1])*t;
		sum-=a[i]-a[i-t];
		sum+=a[i]-a[i-1];
		if(sum<=m) return true;
	}
	return false;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=0,r=n;
	while(l<r){
		int mid=l+r+1>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return ;
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int oT_To=1;
//	cin>>oT_To;
	while(oT_To--) solve();
	return 0;
}
