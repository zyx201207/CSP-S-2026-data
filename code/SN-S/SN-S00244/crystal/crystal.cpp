#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn=5e5+10;
ll n,m;
ll a[maxn];
ll sum,ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll kans=1,wz=1;
	
	for(int i=1;i<=n;i++){
		sum=sum+(i-wz)*(a[i]-a[i-1]);
		while(sum>m){
			sum-=(a[i]-a[wz]);
			wz++;
		}
//		cout<<wz<<" "<<i<<" "<<sum<<" "<<"\n";
		ans=max(ans,i-wz+1);
	}
	cout<<ans;
	return 0;
}
