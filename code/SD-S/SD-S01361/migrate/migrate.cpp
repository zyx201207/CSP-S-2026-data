#include<bits/stdc++.h>
#define ll long long
#define N 2000010
using namespace std;
ll T,n,m,x,l,r,ans,a[N],ls[N],nx[N],f[N],g[N];
int main(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(cin>>T>>T;T--;){
		cin>>n>>m,ls[n+1]=n+1,ans=0;
		for(ll i=1;i<=n;i++)cin>>a[i];
		for(ll i=1,j=1;i<=n;i++){
			for(;a[i]-a[j]>m;j++);
			ls[i]=j;
		}
		for(ll i=n,j=n;i;i--){
			for(;a[j]-a[i]>m;j--);
			nx[i]=j;
		}
		for(ll i=1;i<=n;i++)f[i]=ls[i]^ls[i+1]?f[ls[i]]+ls[i+1]-ls[i]:0;
		for(ll i=n;i;i--)g[i]=nx[i]^nx[i-1]?g[nx[i]]+nx[i]-nx[i-1]:0;
		for(ll i=1;i<=n;i++)if(ls[i]<i-1){
			x=ls[i],l=ls[x+1],r=ls[x+2]-1;
			if(r<l)continue;
			ans+=r-l+1;
			if(ls[x]==l)ans+=f[l]*(1+(nx[x+1]==i)*g[i]);
			if(nx[x+1]==i)ans+=g[i]*(r-l+1);
		}cout<<ans<<"\n";
	}
	return 0;
}
