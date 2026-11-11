#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,e) for(int i=(s);i<=(e);i++)
typedef long long ll;
const int N=5e5+10;
ll a[N];
__int128 s[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,ans=0;
	cin>>n>>m;
	a[0]=0;
	rep(i,1,n){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	s[0]=0;
	rep(i,1,n){
		s[i]=a[i]+s[i-1];
		ll l=1,r=i,mid;
		__int128 ned;
		while(l<r){
			mid=(l+r)>>1;
			ned=a[i]*(i-mid+1)-(s[i]-s[mid-1]);
			if(ned>m){
				l=mid+1;
			}else{
				r=mid;
			}
		}
		ans=max(ans,i-r+1);
		
	}
	cout<<ans;
	return 0;
}