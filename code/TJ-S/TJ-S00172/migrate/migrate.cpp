#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,T;
ll n,d;
ll a[2000005];
ll f[5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>T;
	if(c==11||c==12){
		while(T--){
			cin>>n>>d;
			for(ll i=1;i<=n;i++)cin>>a[i];
			d=(d/(a[2]-a[1]));
			if(d==0||d==1){
				cout<<0<<'\n';
			}
			else{
				d=d*2;
				cout<<max(0ll,n-d+1)<<'\n';
			}
		}
	}
	else while(T--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++)cin>>a[i];
		ll cnt=0;
		for(ll i=1;i<n;i++){
			ll l=i,r=i;
			for(ll i=1;i<=n;i++)f[i]=0;
			f[i]=1;
			while(r<n){
				ll lstr=r;
				for(ll j=r;j>=l;j--){////dp
					for(ll k=j+1;k<=n&&a[k]-a[j]<=d;k++){
						f[k]+=f[j];
						r=max(r,k);//ke yi you hua
					}
					f[j]=0;
				}
				l=lstr;
				if(lstr==r)break;
				for(ll j=lstr+1;j<=r;j++){
					if(f[j]==2)cnt++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
