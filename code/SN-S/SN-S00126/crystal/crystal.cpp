#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],sum[N];
bool check(int x){
	int t=lower_bound(a+1,a+n+1,x)-a;
	int s=x*(t-1)-sum[t-1];
	if(s<=m) return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	} 
	sort(a+1,a+n+1);
	int k=0,l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(a[mid])){
			k=a[mid];
			l=mid+1;
		}else r=mid-1;
	}
	int t=upper_bound(a+1,a+n+1,k)-a;
	cout<<t-1;
	return 0;
}
