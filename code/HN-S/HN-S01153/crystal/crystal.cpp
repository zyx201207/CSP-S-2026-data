#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const int N=5e5+5;

int n,l,ans;ll m;
ll a[N],sum;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	l=n;
	for(int i=n;i>=1;i--){
		if(l>i)l=i,sum=0;
		while(l>1&&sum+a[i]-a[l-1]<=m){
			l--;
			sum+=a[i]-a[l];
		}
		ans=max(ans,i-l+1);
		sum-=1ll*(i-l)*(a[i]-a[i-1]);
	}
	cout<<ans;
	return 0;
}