#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int N=2e5+10;
ll a[N];
char c[N];
ll ans;
ll ls[N],rs[N];
ll wz[N<<2];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		ls[i]=sum;
		sum+=a[i];
		rs[i]=sum;
	}
	int l=1,r=n;
	ll lnow=0,rnow=sum;
	while(l<r){
		ll len=min(rs[l]-lnow,rnow-ls[r]);
//		cout<<len<<' ';
//		cout<<lnow<<" "<<rnow<<' '<<l<<' '<<ls[l]<<' '<<rs[l]<<"  "<<r<<' '<<ls[r]<<' '<<rs[r]<<"  "<<ans<<"    ";
//		if(lnow+len>rnow-len) break;
		if(c[l]!=c[r]) ans+=len;
		int nowl=l;
		if(rs[l]-lnow<rnow-ls[r]){
			l++;
		}
		else if(rs[l]-lnow>rnow-ls[r]){
			r--;
		}
		else l++,r--;
		lnow+=len,rnow-=len;
//		cout<<l<<' '<<ls[l]<<' '<<rs[l]<<"  "<<r<<' '<<ls[r]<<' '<<rs[r]<<"  "<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}
//orange