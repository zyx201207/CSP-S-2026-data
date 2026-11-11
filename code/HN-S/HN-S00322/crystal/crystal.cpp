#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,f;
int a[600005];
int ans; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int sum=0,l=1;
	cin>>n>>m;
	for(int t=1;t<=n;t++) cin>>a[t];
	sort(a+1,a+1+n);
	for(int t=2;t<=n;t++){
		sum+=(t-l)*(a[t]-a[t-1]);
		while(sum>m){
			sum-=(a[t]-a[l]);
			l++;
		}
		f=t-l+1;
		ans=max(f,ans);
	}
	cout<<ans;
	return 0;
}
