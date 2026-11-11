#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,n,d,ans,a[N];
vector<int> b,v;
inline int ef(int i){
	int l=i,r=n,mid;
	while(l<r){
		mid=l+r+1>>1;
		if(a[mid]-a[i]<=d) l=mid;
		else r=mid-1;
	}
	return l;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		if(n<=3){
			cout<<0<<'\n';
			continue;
		}
		ans=0;
		b=vector<int>(N,0);
		v=vector<int>(N,0);
		for(int i=1;i<n-2;++i){
			int l=ef(i+1),p=ef(i+2);
			if(a[i+2]-a[i]<=d&&a[i+3]-a[i]>d&&a[i+3]-a[i+1]<=d){
				
				ans+=b[i]+1;
				if(l==p&&l==i+3) v[l]++;
//				cout<<ans<<' ';
			}
			l=ef(i);
			if(l!=i){
				b[l]+=b[i]+1;
				v[l]+=v[i];
			}
			
			ans+=v[i]*(l-i);
//			cout<<ans<<' '<<v[i]<<' '<<l-i<<'\n';
		}
		for(int i=n-2;i<n;++i){
			if(a[i+1]-a[i]<=d) ans+=v[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}