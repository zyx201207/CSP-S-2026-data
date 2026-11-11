#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll c,t,n,d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12){
			ll c=x[2]-x[1],ans=0;
			for(int i=4;i<=n;i++){
				if(d>=c*(i/2)&&d<c*(i/2+1)&&i%2==0) ans+=n-(i-1);
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int i=2;i<=n;i++){
			if(x[i]-x[i-1]>d) n=i-1;
		}
		ll ans=0;
		for(int len=4;len<=n;len+=2){
			for(int l=1;l+len-1<=n;l++){
				ll r=l+len-1;
				ll L=(l+r)>>1,rr=L+1;
				if(x[L]-x[l]<=d&&x[r]-x[L]<=d&&x[rr]-x[l]<=d&&x[r]-x[rr]<=d){
					ll a=L-1,k=rr+1;
					if((x[a]-x[l]>d)||(x[r]-x[a]>d)||(x[k]-x[l]>d)||(x[r]-x[k]>d)) ans++;
				} 
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
