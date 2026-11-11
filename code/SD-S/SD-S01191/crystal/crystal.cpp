#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],sum[N];
int ans=0;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int z=1;z<=n;++z){
		cin>>a[z];
	}
	sort(a+1,a+n+1);
	sum[1]=a[1];
	for(int z=2;z<=n;++z){
		sum[z]=sum[z-1]+a[z];
	}
	for(int l=1,r=1;r<=n;++r){
		while(a[r]*(r-l+1)-(sum[r]-sum[l-1])>m){
			l++;
		}
		ans=max(r-l+1,ans);
	}
	cout<<ans;
	return 0;
} 
