#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,c,t,d;
ll a[2000050],ans;
vector<ll> f,g,sum;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
//	if(c==0){
//		while(t--){
//			ans=0;
//			cin>>n>>d;
//			for(int i=1;i<=n;i++){
//				cin>>a[i];
//	//			cout<<a[i]<<endl;
//			}
//			f.push_back(0);
//			g.push_back(1);
//			sum.push_back(1);
//			for(int i=2;i<=n;i++){
//				if(a[i]-a[i-1]>d) break;
//				int l=1,r=i-1;
//				while(l<r){
//					int mid=(l+r)>>1;
//					if(a[mid]<a[i]-d) l=mid+1;
//					else r=mid;
//				}
//				int kt=l;
//				f.push_back(f[kt]+1);
//				r=i;
//	//			cout<<a[kt]<<','<<a[i]<<' ';
//				while(l<r){
//					int mid=(l+r+1)>>1;
//					if(f[mid]>f[kt]) r=mid-1;
//					else l=mid;
//				}
//	//			cout<<kt<<','<<l<<' ';
//				g.push_back(sum[l]-sum[kt-1]);
//				sum.push_back(sum[i-1]+g[i]);
//	//			cout<<f[i]<<","<<g[i]<<' ';
//				if(g[i]==2) ans+=n+1-i;
//			}
//	//		cout<<"\n";
//			cout<<ans<<endl;
//		}
//	}else{
		while(t--){
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
	//			cout<<a[i]<<endl;
			}
			for(int j=1;j<=n;j++){
				f.clear();
				g.clear();
				sum.clear();
				for(int i=0;i<j;i++){
					f.push_back(0);
					g.push_back(0);
					sum.push_back(0);
				}
				f.push_back(0);
				g.push_back(1);
				sum.push_back(1);
				for(int i=j+1;i<=n;i++){
					if(a[i]-a[i-1]>d) break;
					int l=j,r=i-1;
					while(l<r){
						int mid=(l+r)>>1;
						if(a[mid]<a[i]-d) l=mid+1;
						else r=mid;
					}
					int kt=l;
					f.push_back(f[kt]+1);
					r=i;
	//				cout<<a[kt]<<','<<a[i]<<' ';
					while(l<r){
						int mid=(l+r+1)>>1;
						if(f[mid]>f[kt]) r=mid-1;
						else l=mid;
					}
	//				cout<<kt<<','<<l<<' ';
					g.push_back(sum[l]-sum[kt-1]);
					sum.push_back(sum[i-1]+g[i]);
	//				cout<<f[i]<<","<<g[i]<<' ';
					if(g[i]==2) ans++;
				}
	//			cout<<"\n";
			}
			cout<<ans<<endl;
		}
//	}
	return 0;
}
