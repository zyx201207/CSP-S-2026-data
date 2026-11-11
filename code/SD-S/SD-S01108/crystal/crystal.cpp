#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500009],h,l=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	h=a[1];
	for(int i=2;i<=n;i++){
		h+=a[i];
		while(a[i]*(l+1)-h<=m and l+1<=i)l++,h+=a[i-l];
		h-=a[i-l];
	}
	cout<<l;
	return 0;
}
