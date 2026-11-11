#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+3;
int n;
ll m,a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)	sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int l=1,r=1;r<=n;r++){
		while(l<r&&sum[r]-sum[l-1]+m<a[r]*(r-l+1))	l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}