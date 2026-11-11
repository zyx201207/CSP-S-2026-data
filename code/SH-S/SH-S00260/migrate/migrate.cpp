#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=2e6+5; 
const ll inf=4e18;
ll n,d,a[N],p[N],s[N],sump[N],sums[N];
int get(ll w){
	return lower_bound(a+1,a+1+n,w)-a;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			sump[i]=sums[i]=a[i]=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			p[i]=get(a[i]-d),s[i]=get(a[i]+d+1)-1;
		a[0]=-inf-1,a[n+1]=inf+1;
		for(int i=1;i<=n;i++){
			int L=p[i],R=p[i+1];
			if(L!=i&&L<R) sump[i]+=sump[L]+((min(R,i))-L);
			else sump[i]=1;
		}
		for(int i=n;i>=1;i--){
			int L=s[i-1],R=s[i];
			if(R!=i&&L<R) sums[i]+=sums[R]+(R-max(L,i));
			else sums[i]=1;
		}
		ll ans=0;
		for(int i=2;i<=n-2;i++){
			int pL=p[i+1],pR=p[i+2];
			int sL=s[i-1],sR=s[i];
			ll wL=pR-pL+(sump[pL]-1)*(p[i]==pL),
			   wR=sR-sL+(sums[sR]-1)*(s[i+1]==sR);
			
			if(pL<i&&pR>pL&&sR>i+1&&sR>sL)
				ans+=wL*wR;
				//cout<<i<<" "<<pL<<" "<<pR<<" "<<sL<<" "<<sR<<endl
		}
		cout<<ans<<endl; 
	}
	return 0;
}

