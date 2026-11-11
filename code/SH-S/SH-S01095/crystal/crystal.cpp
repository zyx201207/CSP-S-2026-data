#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+9;
ll n,m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ll hd=1,tl=1,ans=0,cnt=0;
	while(hd<=n){
		while(cnt+(a[tl+1]-a[tl])*(tl+1-hd)<=m&&tl<n){
			tl++;
			cnt+=(a[tl]-a[tl-1])*(tl-hd);
		}
		//cout<<tl<<" "<<hd<<endl;
		ans=max(ans,tl-hd+1);
		hd++;
		cnt-=a[tl]-a[hd-1];
		//cout<<tl<<" "<<hd<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
