#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+5;
int n,m;
int a[MAXN];
int sum[MAXN];
bool check(int x){
	for(int i=x;i<=n;i++){
		int need=a[i]*(x-1ll)-(sum[i-1]-sum[i-x]);
		if(need<=m) return 1;
	}
	return 0;
}
signed main(){
//	freopen("Asub.txt","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1ll,r=n;
	while(l<r){
		int mid=(l+r)/2ll;
		if(check(mid)) l=mid+1ll;
		else r=mid;
	}
	cout<<l-1ll;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/