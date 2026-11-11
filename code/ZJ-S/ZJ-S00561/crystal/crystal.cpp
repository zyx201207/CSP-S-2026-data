#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
bool check(int mid){
	int sum=0;
	for(int i=1;i<mid;i++){
		sum+=a[i];
	}
	int ans=(mid-1)*a[mid]-sum;
	for(int i=mid+1;i<=n;i++){
		sum+=a[i-1];
		sum-=a[i-mid];
		ans=min(ans,(mid-1)*a[i]-sum);
	}
	return ans<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n,ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
/*
1 2 4 8 9

*/
