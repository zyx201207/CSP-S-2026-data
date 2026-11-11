#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5009;
ll c,T,n,d,ans,x[N],f[N][N],s[N],t[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;ans=0;
		for(ll i=1;i<=n;i++) cin>>x[i];
		for(ll i=1;i<=n;i++) t[i]=lower_bound(x+1,x+1+n,x[i]-d)-x;
		for(ll p=1;p<=n;p++){
			for(ll j=0;j<=n-p;j++)
				for(ll i=p;i<=n;i++)
					f[j][i]=0;
			for(ll i=1;i<=n;i++) s[i]=0;
			f[0][p]=1;
			for(ll j=1;j<=n-p;j++){
				for(ll k=p;k<=n;k++) s[k]=s[k-1]+f[j-1][k];
				for(ll i=p;i<=n;i++) f[j][i]+=s[i-1]-(t[i]==0?0:s[t[i]-1]);
			}
			for(ll k=p;k<=n;k++){
				ll t1=0;
				for(ll j=0;j<=n-p;j++)
					if(f[j][k]){t1=j;break;}
				if(f[t1][k]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
