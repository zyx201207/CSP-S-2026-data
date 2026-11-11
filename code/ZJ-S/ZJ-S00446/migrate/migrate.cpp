#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+5,M=5e5+5,inf=1e17;
ll C,T,n,d,x[N],ww,c[N],ans,s[N],mi[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		if(C==11||C==12){
			for(ll i=1;i<=n;i++) cin>>x[i];
			if(n==1) cout<<"0\n";
			else{
				if(d/(x[2]-x[1])<=1) cout<<"0\n";
				else cout<<n-d/(x[2]-x[1])*2+1<<"\n";
			}
			continue;
		}
		if(C==13||C==14){
			ww=1;
			for(ll i=1;i<=n;i++){
				cin>>x[i];
				while(ww<i&&x[ww]+d<x[i]){
					c[ww]=i-1;
					ww++;
				}
			}
			while(ww<=n){
				c[ww]=n;
				ww++;
			}
			ans=0;
			for(ll i=1;i<n;i++){
				if(c[i]-1==i) continue;
				ans+=c[c[i]-1]-c[c[i]-2];
			}
			cout<<ans<<"\n";
			continue;
		}
		ww=1;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
			while(ww<i&&x[ww]+d<x[i]){
				c[ww]=i-1;
				ww++;
			}
		}
		while(ww<=n){
			c[ww]=n;
			ww++;
		}
		ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i;j<=n;j++){
				mi[j]=inf;
				s[j]=0;
			}
			mi[i]=0;
			for(ll j=i;j<=n;j++){
				if(s[j]==2) ans++;
				for(ll k=c[j];k>=j+1;k--){
					if(mi[k]>mi[j]+1){
						mi[k]=mi[j]+1;
						s[k]=1;
					}else if(mi[k]==mi[j]+1){
						s[k]++;
					}else break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}