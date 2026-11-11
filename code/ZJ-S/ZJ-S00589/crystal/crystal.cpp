#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,m,i;
int a[N],sum[N];
bool pd(int k){
	if(!k) return 1;
	int i;
	for(i=k;i<=n;i++)
		if(a[i]*(k-1)-sum[i-1]+sum[i-k]<=m) return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l,r;
	l=0;r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(pd(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
