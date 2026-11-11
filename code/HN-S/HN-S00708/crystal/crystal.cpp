#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=500010;
int n,m,a[maxn],ans,h[maxn],k[maxn];
bool check(int mid){
	int sum=LLONG_MAX;
	for(int i=mid+1;i<=n;i++){
		if((h[i]-(k[i]-k[i-mid])*(i-mid)-h[i-mid])<=m){
			return 1;
		}
	}
	if(h[mid]<=m)return 1;
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		h[i]=(a[i]-a[i-1])*(i-1)+h[i-1];
		k[i]=k[i-1]+a[i]-a[i-1];
	}
	int l=1,r=n;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid;
			ans=max(ans,mid);
		}else{
			r=mid;
		}
	}
	cout<<ans<<endl;
	return 0;
}
