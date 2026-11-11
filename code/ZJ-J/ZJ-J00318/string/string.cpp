#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll num=2*1e6+5;
ll n,ac[num],ans;
char as[num];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	memset(as,0,sizeof as);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=0;i<n;++i)
		cin>>ac[i]>>as[i];
	ll l=0,r=n-1;
	while(l<r){
		char sa=as[l],sb=as[r];
		ll ca=ac[l],cb=ac[r];
		ll minn=min(ca,cb);
		if(ca>cb){
			ac[l]-=minn;
			ac[r]=0;
			--r;
		}
		else if(ca==cb){
			ac[r]=0;
			ac[l]=0;
			--r;
			++l;
		}
		else{
			ac[r]-=minn;
			ac[l]=0;
			++l;
		}
		if(sa!=sb)
			ans+=minn;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}