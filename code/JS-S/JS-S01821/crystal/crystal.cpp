#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[5000005],sum[5000005],tot[50000005],t;
bool check(int x,int endd){
	if(sum[endd-1]-sum[x-1]+m>=a[endd]*(endd-x)) return true;
	return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	sum[1]=a[1];
	for(int i=2;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(check(mid,i)) r=mid;
			else l=mid+1;
		}
		tot[i]=i-l+1;
	}
	sort(tot+1,tot+n+1);
	cout<<tot[n]<<endl;
	return 0;
}
