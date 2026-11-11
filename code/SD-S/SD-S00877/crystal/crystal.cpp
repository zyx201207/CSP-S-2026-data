#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+100; 
ll a[N];
ll n,m,ans,res,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll L=1;
	for(int i=1;i<=n;i++){
		res+=(i-L)*(a[i]-a[i-1]);
		cnt++;
		while(L<=i&&res>m){
			res-=(a[i]-a[L]);
			L++;
			cnt--;
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<"\n";
	return 0;
}
