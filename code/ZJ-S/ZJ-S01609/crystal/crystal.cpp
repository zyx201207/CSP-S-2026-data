#include<bits/stdc++.h>
#define int long long
using namespace std;
int _,n,m,a[500010],CSP_RP=1e18,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int sum=0,l=1;
    for(int i=2;i<=n;i++){
    	sum+=(a[i]-a[i-1])*(i-l);
    	while(l<i&&sum>m){
    		sum-=(a[i]-a[l]);
    		l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	CSP_RP++;
    return 0^_^0;
}
/*
Oct31==Dec25? xiakule
RP++;
14:43 AC le,haha
love CCF
//freopen
froepen
ni bei pian le
luogu uid 1456012
*/