#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll x[N];

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--) {
		ll n,d;
		cin>>n>>d;
		ll e=0;
		int f=1;
		for(int i=1; i<=n; i++) {
			cin>>x[i];
			ll u=0;
			if(f==1&&i>=2)u=x[i]-x[i-1];
			if(i==2) e=u;
			if(f==1&&u!=e){
				f=0;
			}
		}
		if(n==1) {
			cout<<"0\n";
			continue;
		}
		if(f==1){
			int ans=0;
			for(int i=1;i<=n;i++){
				int q=i+3;
				if(q>n) continue;
				if(x[q]-x[i]<=2*d){
					ans++;
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		int ans=0;
		for(int i=1; i<=n; i++) {
			int q=lower_bound(x+1,x+1+n,x[i]+2*d)-x-1;//找到第一个满足的
			while(i<q) {
				if(x[q]-x[i]>2*d) q--;
				if(q<=i+1||x[q]-x[i]==d*2) {
					q--;
					continue;
				}
				int l=0,r=0;
				if(x[q]-d<=x[i]) l=i;
				else l=lower_bound(x+i,x+1+q,x[q]-d)-x-1;
				if(x[l]-x[i]>d||l<i) {
					q--;
					continue;
				}
				if(x[i]+d>=x[q]) r=q;
				else r=lower_bound(x+i,x+1+q,x[i]+d)-x-1;
				if(x[q]-x[r]>d||r>q) {
					q--;
					continue;
				}
				if(l==r-1) {
					ans++;
					break;
				}
				if(l==r)break;
				q--;
			}
		}
		cout<<ans<<"\n";
	}



	return 0;
}
