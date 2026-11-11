#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=500010;
ll n,m,a[N],ans=1;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	ll cnt=0,an=1;
	for(ll l=1,r=1;r<=n;){
		r++;
		cnt+=an*(a[r]-a[r-1]);
		an++;
		while(cnt>m&&l<=r){
			cnt-=a[r]-a[l];
			l++;
			an--;
		}
		ans=max(ans,an);
		
	}
	cout<<ans<<endl;
	return 0;
}
