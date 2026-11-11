#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=2e6+5;
ll cc,t,ans=0,suc=0;
ll a[M],c[M];
ll n,d;
void sol(ll l,ll r,ll k){
    if(suc>2){
		return;
	}
	for(ll i=l;i<=r-1;i++){
		for(ll j=i+1;j<=r;j++){
		    if((c[j]-c[i])<=d){
		    	if(j==r){
		    		suc++;
		    		continue;
				}
				if(k-1==0){
					continue;
				}
		    	sol(j,r,k-1);
			}	
		}	
	}	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>cc>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		if(d==1){
			int tm=0;
			cout<<tm;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			c[i]=a[i]-a[1];
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					continue;
				}
				if(a[j]-a[j-1]>d){
					j=n;
					continue;
				}
				if(j-i==3){
					ans++;
					continue;
				}
				ll s;
				if((a[j]-a[i])%d!=0){
					s=(a[j]-a[i])/d+1;
				}
				else{
					s=(a[j]-a[i])/d;
				}
				suc=0;
				sol(i,j,s);
				if(suc==2){
					ans++;
				}
			}
		}
    cout<<ans<<'\n';
	}
	return 0;
}
