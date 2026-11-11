#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,m,a[N],ans;
signed main(){
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ll tmp=0,l=1;
	for(int i=1;i<=n;i++){
		while(l<i && tmp>m){
			tmp-=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
		if(i<n) tmp+=(a[i+1]-a[i])*(i-l+1);	
	}
	cout<<ans;
	return 0;
}
