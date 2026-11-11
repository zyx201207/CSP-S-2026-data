#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],sum[maxn],d[maxn],ans;
int max(int a,int b){
	if(a>=b) return a;
	else return b;
}
int find(int l,int r,int x){
	if(l==r) return l;
	int mid=(l+r)>>1;
	if(m==sum[x]-sum[mid]-(d[x]-d[mid])*mid) return mid;
	else if(m>sum[x]-sum[mid]-(d[x]-d[mid])*mid) find(l,mid,x);
	else find(mid+1,r,x);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;++i){
		sum[i]=a[i]-a[i-1];
		d[i]=sum[i];
	}
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+sum[i]*(i-1);
		d[i]+=d[i-1];
		if(sum[i]<=m){
			ans=max(ans,i);
		}
		else {
			ans=max(ans,i-find(1,i,i));
		}
	}
	cout<<ans;
	return 0;
}
