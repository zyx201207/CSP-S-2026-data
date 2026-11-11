#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2123456;
ll n,d;
ll a[N],p[N],s[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll T;
	cin>>T>>T;
	while(T--){
		cin>>n>>d;
		cin>>a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		ll l=1,r=1;
		
		while(r<=n){
			if(a[r]-a[l]<=d){
				p[r]=r-l;
				
				r++;
			}else l++;
		}
		l=1,r=1;
		while(r<=n){
			if(p[r]==0)l=r;
			if(r-1>=l&&p[r-1]>=p[r]){
				if(p[r]==2)s[r]=r-l-2;
				l=r-p[r];
			}
			r++;
		}
		
		l=r=n;
		while(l){
			if(a[r]-a[l]<=d){
				p[l]=r-l;
				l--;
			}else r--;
		}
//		for(int i=1;i<=n;i++)cout<<p[i]<<' ';
		l=n,r=n;
		while(l){
			if(p[l]==0)r=l;
			
			if(r-1>=l&&p[l+1]>=p[l]){
				if(p[l]==2){
					if(s[l+3]==0)s[l+3]=r-l-5;
					else s[l+3]*=max(1ll,r-l-5);
				}
				r=l+p[r];
			}
			l--;
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			ans+=s[i];
			s[i]=0;
		}
		cout<<ans<<'\n';
	}
	return 0;
}