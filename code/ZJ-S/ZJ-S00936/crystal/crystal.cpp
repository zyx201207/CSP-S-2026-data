#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010];
int cz[500010];
int sum[500010];
int ck(int cz){
	if(n*(n-1)/2*cz<=m)return n;
	int ans=1;
	int l=1,r=n-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(mid*(mid-1)/2*cz<=m){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return ans;
}
int solve(){
	int l=1,r=n,ans=1,flag=0;
	while(l<=r){
		int mid=(l+r)>>1;
		flag=0;
		for(int i=1;i+mid-1<=n;i++){
			int j=i+mid-1;
			if(cz[j]*(mid-1)-sum[j-1]+sum[i-1]<=m){
				flag=1;
				ans=mid;
				break;
			}
		}
		if(flag)l=mid+1;
		else r=mid-1;
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cz[i]=a[i]-a[1];
		sum[i]=sum[i-1]+cz[i];
	}
	if(n==1)cout<<1;
	else if(n==2){
		if(abs(a[2]-a[1])<=m)cout<<2;
		else cout<<1;
	}
	else{
		cout<<solve();
	}
	return 0;
}
