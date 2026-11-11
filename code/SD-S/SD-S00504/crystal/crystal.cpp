#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,m;
int a[maxn],f[maxn];
bool check(int x){
	for(int i=x;i<=n;i++){
		if(a[i]*x-f[i]+f[i-x]<=m)return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
	}
	int l=1,r=5e5;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<r<<endl;
	return 0;
}
