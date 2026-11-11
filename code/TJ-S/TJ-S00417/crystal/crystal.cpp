#include <bits/stdc++.h>
#define ll long long
const int N=5e5+10;
ll a[N];
ll s[N];
ll knd,ans,mx;
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	s[0]=0;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(ll i=0;i<n;i++){
		s[i]=a[i]-s[i-1]; 
    }
	for(int i=0;i<n;i++){
	    if(ans+abs(s[i])>m+1) break;
	    ans+=abs(s[i]);
	    knd++;
	}
     cout<<knd;	
	return 0;
} 
