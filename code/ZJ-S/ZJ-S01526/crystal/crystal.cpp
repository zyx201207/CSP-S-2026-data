#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m,a[N],cost,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll l=1,r=1;l<=n;l++){
		while(cost+(a[r+1]-a[r])*(r-l+1)<=m&&r<n){
			r++;
			cost+=(a[r]-a[r-1])*(r-l);
		}
		ans=max(ans,r-l+1);
		cost-=a[r]-a[l];
	}
	cout<<ans;
	return 0;
}