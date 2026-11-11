#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200010][35],ans,c[200010],d,e[200010];
inline ll read(){
	ll s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();m=read();
	for(ll i=1;i<=n;i++){
		ll x=read(),cnt=0;
		while(x){
			if(x%2) a[i][cnt]=1;
//			cout<<a[i][cnt];
			cnt++;
			x>>=1;
		}
//		cout<<"\n";
		c[++d]=i;
	}
	for(ll i=31;i>=0;i--){
		ll s=0;
		for(ll j=1;j<=d;j++) s+=a[c[j]][i];
//		cout<<i<<" "<<s<<" "<<d<<"\n";
//		cout<<"\n";
		if(s>=m){
			ans+=(1ll)<<i;
			ll d2=0;
			for(ll j=1;j<=d;j++){
				if(a[c[j]][i]){
					c[++d2]=c[j];
				}
			}
			d=d2;
		}
	}
	printf("%lld",ans);
}
