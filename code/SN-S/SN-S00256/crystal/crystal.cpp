#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
inline bool check(int k){
	int sum=0;
	for(int i=1;i<k;i++){
		sum+=a[i];
	}
	for(int i=k;i<=n;i++){
		sum+=a[i]-a[i-k];
		if(a[i]*k-sum<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	if(check(r)) cout<<r;
	else cout<<l;
	return 0;
}
