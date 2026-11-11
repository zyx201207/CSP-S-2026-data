#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,cnt,maxn,maxm;
const int N=5e5+5;
ll m;
ll a[N],sum[N];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=i,r=i;
		ll x=0;
		while(1){	
			if(l==1&&r==n){
				break;
			}
			ll xl=2000000000000,xr=2000000000000;
			if(l>1){
				xl=a[i]-a[l-1];
			}
			if(r<n){
				xr=a[r+1]-a[i];
			}
		
			if(xl<=xr){
				if(x+xl<=m){
					x+=xl;
					l--;
				}
				else{
					break;
				}
			}
			else{
				if(x+xr<=m){
					x+=xr;
					r++;
				}
				else{
					break;
				}
			}
		}
		if(r-l+1>maxn){
			maxn=r-l+1;
			maxm=i;
		}
	}
	cout<<maxn;
	return 0;
}

