#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],ans,sum[500010],l,r;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
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
	l=0;
	r=1;
	while(r<=n){
		r++;
		while(a[r]*(r-l)-sum[r]+sum[l]>m){
			l++;
		}
		ans=max(ans,r-l);
	}
	cout<<ans;
	return 0;
}