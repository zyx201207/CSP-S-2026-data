#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
const int N=2e6+5;
ll x[N],c,t,n,d,last[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll ans=0;
		cin>>n>>d;
		memset(last,0,sizeof last);
		memset(x,0,sizeof x);
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int l=1,r=2;
		while(l<=n){
			while(x[r]-x[l]<=d&&r<=n) r++;
			last[l]=r-1;
			l++;
			r=l+1;
		}
		for(int i=1;i<=n;i++){
			if(last[i]-i+1<=2) continue;
			int k=last[i]-1;
			if(last[k-1]>=last[k]) continue;
			ans+=last[k]-last[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}