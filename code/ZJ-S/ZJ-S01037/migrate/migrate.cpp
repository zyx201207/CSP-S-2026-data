#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+29;
ll c,t,n,m;
ll a[N],ans;
inline ll read(){
	char x;
	ll sum=0,f=1;
	x=getchar();
	while(x<'0'||x>'9'){
		if(x=='-') f=-1;
		x=getchar();
	}
	while('0'<=x&&x<='9'){
		sum=sum*10+x-'0';
		x=getchar();
	}
	return sum*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	while(t--){
		n=read();
		m=read();
		for(ll i=1;i<=n;i++) a[i]=read();
		if(c==0||c==11||c==12){
			ll d=a[2]-a[1];
			ll k=(m<d)?0:m/d;
			cout<<((k==0||k==1)?0:max(n-2*k+1,0ll))<<"\n";
		}else{
			ans=0;
			for(ll i=2;i<n;i++){
				if(a[i+1]-a[i]<=m&&a[i]-a[i-1]<=m) ans++;
			}
			cout<<ans<<"\n";
		}
	}
} 
