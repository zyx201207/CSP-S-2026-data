#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],sum,ans,l=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-l);
		while(sum>m) sum-=(a[i]-a[l++]);
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
