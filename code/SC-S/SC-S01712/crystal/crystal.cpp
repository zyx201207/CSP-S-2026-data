#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=5e5+7;
ll n,m,a[maxn],sum[maxn],l,r,ans=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	l=1,r=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(;r<=n;){
		if((r-l)*a[r]-(sum[r-1]-sum[l-1])>m){
			l++;
		}else{
			r++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans-1;
	return 0;
}