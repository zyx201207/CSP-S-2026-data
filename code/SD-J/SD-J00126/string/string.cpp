#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using ll=long long;
using namespace std;
const int N=2e5+10;
ll a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string s="";
	ll len=0;
	int pos=0;
	rep(i,1,n){
		cin>>a[i]>>c[i];
		rep(i,1,a[i]){
			s+=c[i];
		}
		len+=a[i];
	}
//	cout<<s<<"\n";
	ll lenl=0;
	rep(i,1,n){
		lenl+=a[i];
		if(lenl>=len/2){
			pos=i;
			break;
		}
	}
	string rs=s;
	reverse(rs.begin(),rs.end());
	if(s==rs){
		cout<<"0\n";
		return 0;
	}
	ll ans=len/2;
//	cout<<ans<<"\n";
	ll llen=0,rlen=0;
	for(ll l=1,r=n;l<r;++l,--r){
		if(l==r)break;
//		cout<<l<<" "<<r<<" "<<ans<<"\n";
		ll nllen=a[l],nrlen=a[r];
		while(c[r-1]==c[r]&&r-1>pos&&l<r-1){
			r--;
			nrlen+=a[r];
		}
		while(c[l+1]==c[r]&&l-1<pos&&l+1<r){
			l++;
			nllen+=a[l];
		}
		ll mxc=abs(llen-rlen);
//		cout<<l<<" "<<r<<" "<<ans<<"\n";
		if(c[l]==c[r]&&l<r){
			ans-=max(min(nllen,nrlen)-mxc,0LL);
//			cout<<"998\n";
		}
		llen+=nllen;
		rlen+=nrlen;
	}
//	if(lenl!=len/2){
//		ans-=min(len/2-(lenl-a[pos]),lenl-len/2);
//	}
//	int maxn=
//	rep(i,1,26){
//		
//	}
	cout<<ans<<"\n";
	return 0;
}
