#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],sum[N];
int count(int l,int r){
	int res=0;
	res=(r-l)*a[r]-(sum[r-1]-sum[l-1]);
	return res;
}
bool check(int len){
	int res=0x3f3f3f3f;
	for(int l=1;l+len-1<=n;++l){
		res=min(res,count(l,l+len-1));
	}
	if(res<=m)return 1;
	else return 0;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
	int l=1,r=n,ans=0;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}