#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const int N=1e6+10,M=1e3+10,MOD=1e9+7;
ll n,a[N],ans=0;
char s[N];
int main(){
	fastio;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i]>>s[i];
	ll l=1,r=n,lx=1,rx=a[r];
	while(l<r){
		ll ly=a[l]-lx+1;
		ll ry=rx;
		ans+=min(ly,ry)*(s[l]!=s[r]);
		if(ly<ry){
			l++,lx=1;
			rx-=ly;
		}else if(ry<ly){
			r--,rx=a[r];
			lx+=ry;
		}else{
			l++,lx=1;
			r--,rx=a[r];
		}
	}
	cout<<ans;
	return 0;
}
