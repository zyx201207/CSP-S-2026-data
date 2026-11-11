#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;ll a[500500];
ll s=1;ll p=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++)f[i]=a[i];
	ll l=1,r=1;
	for(l=1;l<=n;l++){
		while(p+(a[r+1]-a[r])*(r-l+1)<=m&&r<n){
			r++;
//			cout<<(a[r]-a[r-1])*(r-l)<<"\n";
			p+=(a[r]-a[r-1])*(r-l);
		}
		s=max(s,r-l+1);
//		cout<<l<<" "<<r<<"\n";
		p-=(a[r]-a[l]);
	}
	cout<<s<<"\n";
}
// 500 000 000 000 000 000
//9223 372 036 854 775 808
