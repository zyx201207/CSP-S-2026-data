#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN=5e5+5;
long long n,m,a[MAXN],d[MAXN];
bool cmp(long long x,long long y){
	return x<y;
}
bool check(int mid){
	long long sum=0;
	for(int i=1;i+mid-1<=n;i++){
		d[i]=a[i+mid-1]-a[i];
	}
	for(int i=1;i<=mid;i++){
		sum+=(a[mid]-a[i]);
	}
	if(sum<=m) return 1;
	for(int i=2;i+mid-1<=n;i++){
		sum=sum-d[i-1]+(mid-1)*(a[i+mid-1]-a[i+mid-2]);
		if(sum<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}
	cout<<ans<<"\n"; 
	return 0;
}
