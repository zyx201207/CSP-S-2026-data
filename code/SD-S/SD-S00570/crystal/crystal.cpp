#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[500005],l=1,m,sum[500005],mx;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int r=1;r<=n;r++){
		while(a[r]*(r-l+1)-sum[r]+sum[l-1]>m) ++l;
		mx=max(mx,r-l+1);
	}
	cout<<mx;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
