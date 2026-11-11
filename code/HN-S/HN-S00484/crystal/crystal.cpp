#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m,a[N],sum[N];
bool check(int k){
	for(int i=1;i<=n-k+1;i++){
		int x=i+k-1;
		int ans=a[x]*k-(sum[x]-sum[i-1]);
		if(ans<=m){
			return true;
		}
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=-1,r=n+1;
	while(l+1!=r){
		int mid=(l+r)/2;
		if(check(mid)==true){
			l=mid;
		}else{
			r=mid;
		}
	}
	cout<<l;
	return 0;
} 
