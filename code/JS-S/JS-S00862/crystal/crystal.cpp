#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int a[N],s[N],n,m;
bool check(int len){
	for(int i=1;i+len-1<=n;i++){
		if(s[i+len-1]-s[i-1]+m>=a[i+len-1]*len)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<r;
}
