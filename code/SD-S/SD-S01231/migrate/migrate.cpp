#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
#define ll long long
const ll maxn=2e6+27;
const ll INF=LONG_LONG_MAX;
ll a[maxn],f[maxn];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof a);
		ll n,m;
		cin>>n>>m;
		
		for(ll i=1;i<=n;i++){
			cin>>a[i];
			if(i==1){
//				cout<<"ok"<<endl;
//				r=a[i];
//				cout<<endl<<"r="<<r<<endl;
			} 
//			printf("%lldn",a[i]);
		}
//		cout<<endl<<endl;
//		cout<<r<<endl;
		ll r=a[1];
		if(r<0){
			for(ll i=1;i<=n;i++){
				a[i]-=r;
//				cout<<a[i]<<" ";
			}
		}
		
		for(ll i=a[1];i<=a[1]+m;i++)
			f[i]=1;
		for(ll i=a[1]+m+1;i<=n;i++)
			f[i]=0;
		
//		for(ll i=1;i<=n;i++)
//			cout<<a[i]<<" ";
//		cout<<endl;

		ll p=1,q=n;
		a[0]=INF;
		a[n+1]=-INF;
		for(ll i=n;i>=p;i--){
			if(a[i+1]-a[i]>=m)
				q=i;
		}
//		cout<<p<<" "<<q<<" ";
//		cout<<endl;
		
//		for(ll i=p;i<=q;i++)
//			cout<<a[i]<<" ";

		ll ans=0;
//		for(ll i=1;i<=n;i++)
//			cout<<f[i]<<" ";
			
		for(ll i=p+1;i<=q;i++){
//			cout<<i<<"  ";
			if(a[i]-a[p]>m){
				ll fx=0;
				for(ll j=a[i]-1;j>=a[i]-m&&j>=p;j--){
					fx+=f[j];
//					cout<<"j="<<j<<" : f[j]="<<f[j]<<" fx="<<fx<<" "<<endl;
				}
				f[a[i]]=fx;
//				cout<<"f[a[i]]="<<f[a[i]]<<" ";
				if(f[a[i]]%2==0){
					ans++;
				}else{
//					cout<<"YES ";
					ll p1=p;
					bool ip=0;
					do{
						f[a[i]]-=a[p1];
						if(f[a[i]]==2){
							ans++;
							ip=1;
						}
						p1++;
					}while(p1<=a[i]-m-1&&ip==0);	
				}
			}
//			cout<<ans<<" ";
//			cout<<endl<<endl;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
/*
0 1
6 2
-4 -3 -2 -1 3 6
*/

