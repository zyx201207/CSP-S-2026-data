#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=2e5+9;
ll n,a[N],ans;
char c[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll pi=1,pj=n;
	for(ll i=1;i<=n;i++) cin>>a[i]>>c[i];
	while(pi<pj){
		if(a[pi]>a[pj]){
			a[pi]-=a[pj];
			if(c[pi]!=c[pj]) ans+=a[pj];
			pj--;
		}
		else if(a[pi]==a[pj]){
			if(c[pi]!=c[pj]) ans+=a[pj];
			pi++,pj--;
		}
		else{
			a[pj]-=a[pi];
			if(c[pi]!=c[pj]) ans+=a[pi];
			pi++;
		}
	}
	cout<<ans;
	return 0;
}
