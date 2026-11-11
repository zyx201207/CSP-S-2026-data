#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,sum=0;
int a[500005],b[500005],ans[500005];
bool check(int mid){
	for(int i = mid+1;i <= n;i++){
		int x=ans[i]-ans[i-mid]-(a[i]-a[i-mid])*(i-mid-1);
		if(x<=m){
			sum=max(sum,mid+1);
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	for(int i = 2;i <= n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i = 1;i <= n;i++){
		ans[i]=ans[i-1]+b[i]*(i-1);
	}
	int l=0,r=n;
	while(l+1<r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	cout<<sum;
	return 0;
}
