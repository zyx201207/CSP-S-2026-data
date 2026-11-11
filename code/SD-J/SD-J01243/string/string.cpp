#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll n,a[N],pre[N],ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i]>>c[i],pre[i]=pre[i-1]+a[i];
	ll yb=0,xz=1;
	while(yb+a[xz]<=pre[n]/2) yb+=a[xz],xz++;
	if(yb<pre[n]/2) yb=pre[n/2];
	else xz--;
	ll l=1,r=n;
	while(l<=xz){
		ll xy=0,r_sum=0;
		while(r_sum<a[l]){
			if(r_sum+a[r]>a[l]){
				ll js=a[l]-r_sum;
				a[r]-=js;
				r_sum+=js;
				if(c[r]!=c[l]) xy+=js;
				break;
			}
			r_sum+=a[r];
			if(c[r]!=c[l]) xy+=a[r];
			r--;
		}
		ans+=xy;
		l++;
	}
	cout<<ans;
	return 0;
} 
