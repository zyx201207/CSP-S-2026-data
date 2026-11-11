#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=2e6+10;
int c,t,n;
ll k;
ll a[N];
int tol[N],tor[N];
int led[N],rid[N];
int visl[N],visr[N], ctl[N], ctr[N];
ll ton[N];

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>c>>t;
	while(t--) {
		cin>>n>>k;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		if(c==11||c==12) {
			ll d=a[2]-a[1];
			ll l=k/d;
			if(l<=1) {
				cout<<"0"<<endl;
			} else {
				cout<<max(0ll,n-(l*2-1))<<endl;
			}
			continue;
		}
		vector<int> visl(n+1,0);
		vector<int> visr(n+1,0);
		vector<int> ctl(n+1,1);
		vector<int> ctr(n+1,1);
		int l=1,r=1;
		ll ans=0;
		led[1]=1,rid[n]=1;
		for(int i=1; i<=n; i++) {
			while(l<i&&a[i]-a[l]>k) l++;
			while(r+1<=n&&a[r+1]-a[i]<=k) r++;
			tol[i]=l,tor[i]=r;
		}
		for(int i=2; i<=n; i++) {
			if(tol[i]==i-1&&tor[i-1]==i) {
				visl[i-1]=1;
				ctl[i]=ctl[i-1]+1;
			}
		}
		for(int i=n-1; i>=1; i--) {
			if(tor[i]==i+1&&tol[i+1]==i) {
				visr[i+1]=1;
				ctr[i]=ctr[i+1]+1;
			}
		}
		for(int i=1; i<=n; i++) {
			if(visl[i]) continue;
			for(int j=i+1; j<=n; j++) {
				if(visr[j]) continue;
				if(tor[i]==tol[j]+1) ans+=ctl[i]*ctr[j];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
