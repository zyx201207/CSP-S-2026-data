#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[500010],sum[500010];
int main(){
	// freopen("E:\\down\\crystal\\crystal4.in","r",stdin);
	// freopen("E:\\down\\crystal\\crystal4.out","w",stdout);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<r){
			int mid=(l+r+1)/2;
			if(a[mid]*(mid-i+1)-(sum[mid]-sum[i-1])<=m){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,l-i+1);
	}
	cout<<ans;
	return 0;
}