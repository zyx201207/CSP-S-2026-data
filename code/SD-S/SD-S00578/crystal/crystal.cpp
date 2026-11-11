#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
int n,m;
int a[500005];
int sum[500005];
bool kfc(int x){
	if(x==1) return true;
	for(int l=1;l+x-1<=n;l++){
		int r=l+x-1;
		int s=sum[r]-sum[l-1];
		if(a[r]*x-s<=m) return true;
	}
	return false;
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
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(kfc(mid)) l=mid+1;
		else r=mid-1; 
	}
	cout<<r;
	return 0;
}

