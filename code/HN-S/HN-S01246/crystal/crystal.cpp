#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+7;
int n,m,a[N],sum[N],ans;
bool check(int mid){
	for(int i=mid;i<=n;i++){
		if(m>=a[i]*mid-(sum[i]-sum[i-mid-1])) return true;
	}
	return false;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
        if(check(mid)){
        	ans=mid;
        	l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
} 
