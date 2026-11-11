#include<bits/stdc++.h>

#define ll long long
#define ris(x,y,z) for(ll x=y;x<z+1;++x)
#define ful(x,y,z) for(ll x=y;x>z-1;--x)
#define riso(x,y,z,a) for(ll x=y;x!=a;x=z)
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);

using namespace std;

const ll N=5e5+5;

ll n,m,a[N],s[N],ans=1;

signed main(){
	fre("crystal");
	ios::sync_with_stdio(0);
	cin.tie(0),
	cout.tie(0);
	cin>>n>>m;
	ris(i,1,n)
		cin>>a[i];
	sort(a+1,a+1+n);
	ris(i,1,n)
		s[i]=s[i-1]+a[i];
	ll l,r,mid;
	ful(i,n,2){
		l=0,r=i-1;
		while(l<r-1){
			mid=(l+r-1)/2+1;
			if(((i-mid+1)*a[i]-s[i]+s[mid-1])<=m){
				//cout<<i<<' '<<l<<' '<<mid<<' '<<r<<' '<<((i-mid+1)*a[i]-s[i]+s[mid-1])<<"<="<<m<<'\n';
				r=mid;
			}
			else
				l=mid;
		}
		//cout<<ans<<' ';
		ans=max(ans,i-r+1);
		//cout<<i<<' '<<l<<' '<<r<<' '<<i-r+1<<'\n';
	}
	cout<<ans<<'\n';
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
