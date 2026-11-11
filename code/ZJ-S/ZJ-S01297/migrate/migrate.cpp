#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
ll c,T,n,d,a[N],r[N],l[N],sl[N],el[N],sr[N],er[N],disl[N],disr[N];
void dfsl(int u){
	ll cnt=1;
	disl[u]=1;
	while(u!=n){
		u=r[u];
		disl[u]+=++cnt;
		if(u==r[u]) break;
	}

}
void dfsr(int u){
	ll cnt=1;
	disr[u]=1;
	while(u!=1){
		u=l[u];
		disr[u]+=++cnt;
		if(u==l[u]) break;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		ll ans=0;
		ll cha=0,flag=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=2){
				if(i==2) cha=a[i]-a[i-1];
				else if(cha!=a[i]-a[i-1]){
					flag=1;
				}
			}
			disl[i]=disr[i]=0;
		}
		if(flag==0){
			ll ge=d/cha;
			ll lw=ge+1;
			ll hi=min(ge+1,n-1);
			cout<<(n-lw+1+n-hi+1)*(hi-lw+1)/2<<'\n';
			continue;
		}
		ll p=1;
		for(int i=1;i<=n;i++){
			while(p<=n){
				if(a[p]-a[i]<=d) p++;
				else break;
			}
			r[i]=p-1;
		}
		p=n;
		for(int i=n;i>=1;i--){
			while(p>=1){
				if(a[i]-a[p]<=d) p--;
				else break;
			}
			l[i]=p+1;
		}
		ll pl=1,pr=1;
		for(int i=1;i<=n;i++){
			if(!disl[i]) dfsl(i);
		}
		for(int i=n;i>=1;i--){
			if(!disr[i]) dfsr(i);
		}
		for(int i=1;i<n;i++){
			sl[i]=sr[i]=el[i]=er[i]=0;
			while(pr<n&&r[pr]<i+1) pr++;
			if(r[pr]==i+1){
				sr[i]=er[i]=pr;
				while(pr<n&&r[++pr]==i+1){
					el[i]=pr;
				}
			}
			while(pl<n&&l[pl]<i) pl++;
			if(l[pl]==i){
				sl[i]=el[i]=pl;
				while(pl<n&&l[++pl]==i){
					el[i]=pl;
				}
			}
			if(sl[i]&&sr[i]&&!(sr[i]>el[i])){
				ll totl=0;
				ll totr=0;
				totl=disl[sr[i]];
				totl+=(er[i]-sr[i]);
				totr=disr[sl[i]];
				totl+=(el[i]-sl[i]);
				ans+=totl*totr;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

