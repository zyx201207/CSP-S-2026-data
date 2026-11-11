#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n;
ll m;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int ans=1;
	ll sum=0;
	for (int l=1,r=1;r<=n;r++){
		sum+=1ll*(a[r]-a[r-1])*(r-l);
		while (sum>m&&l<r) sum-=(a[r]-a[l]),l++;
		ans=max(ans,r-l+1); 
	}
	cout<<ans;
	return 0;
}
