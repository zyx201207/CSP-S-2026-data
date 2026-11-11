#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],F,k,ans=1;
inline ll read(){
	ll s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(ll i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	k=a[2]-a[1];
	for(ll i=3;i<=n;i++){
		if(a[i]-a[i-1]!=k){
			F=1;
			break;
		}
	}
	if(!F){
		ll l=0,r=n-1,s=0;
		while(l<=r){
			ll mid=l+r>>1;
			if((k+mid*k)*mid<=2*m) s=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%lld",s+1);
	}
	else if(n<=5000){
		for(ll i=2;i<=n;i++){
			ll s=0;
			for(ll j=1;j<=i;j++) s+=a[i]-a[j];
			if(s<=m){
				ans=max(ans,i);
				continue;
			}
//			ll cnt=0;
			for(ll j=1;j<=i;j++){
				if(s-(a[i]-a[j])<=m){
					ans=max(ans,i-j);
					break;
				}
				s-=a[i]-a[j];
			}
		}
		printf("%lld",ans);
	}
	else{
		printf("%lld",n);
	}
}
