#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
int n;
ll m;
ll a[N];
int ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	ll k=0;
	int l=1,r=1;
	for(;k+(r-l+1)*(a[r+1]-a[r])<=m&&r<n;r++)	k+=(r-l+1)*(a[r+1]-a[r]);
	ans=max(ans,r-l+1);
	while(r<n){
		k-=(a[r]-a[l]);
		l++;
		r=max(r,l);
		for(;k+(r-l+1)*(a[r+1]-a[r])<=m&&r<n;r++)	k+=(r-l+1)*(a[r+1]-a[r]);
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
