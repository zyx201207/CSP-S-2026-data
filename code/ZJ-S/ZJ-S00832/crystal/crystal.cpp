#include<bits/stdc++.h>
using namespace std;
const long long maxn=500000;
int n,ans=0;
long long m,a[maxn+5];

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=1;
	long long sum=0;
	while(l<=n){
		while(r<n&&sum+(a[r+1]-a[r])*(r-l+1)<=m){
			sum=sum+(a[r+1]-a[r])*(r-l+1);
			r++;
		}
		ans=max(ans,r-l+1);
		sum=sum-(a[r]-a[l]);
		l++;
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
//14:43 做完第一题了 :)
//致敬传奇机长lvzekai