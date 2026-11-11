#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+3;
int a[maxn];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i+3<=n;i++){
			if(a[i+3]-a[i]>d && a[i+3]-a[i+1]<=d && a[i+2]-a[i]<=d){//i+1 i+2
				int t1,t2,l,r;
				l=1,r=i;
				while(l<=r){
					int mid=(l+r)>>1;
					if(a[i+2]-a[mid]<=d){
						t1=mid;
						r=mid-1;
					}else{
						l=mid+1;
					}
				}
				l=i+3,r=n;
				while(l<=r){
					int mid=(l+r)>>1;
					if(a[mid]-a[i+1]<=d){
						t2=mid;
						l=mid+1;
					}else{
						r=mid-1;
					}
				}
				ans+=(i+1-t1)*(t2-i-2);
				int t3,t4;
				r=t1-1,l=1;
				while(l<=r){
					int mid=(l+r)>>1;
					if(a[t1+1]-a[mid]>d){
						t3=mid;
						l=mid+1;
					}else{
						r=mid-1;
					}
				}
				for(int i=t3;i>=1;i--){
					if(a[t1]-a[i]<=d && a[t1+1]-a[i]>d){
						ans+=t2-i-3;
					}else if(a[t1]-a[i]>d)break;
				}
				l=t2+1,r=n;
				while(l<=r){
					int mid=(l+r)>>1;
					if(a[i]-a[t2-1]>d){
						t4=mid;
						r=mid-1;
					}else{
						l=mid+1;
					}
				}
				for(int i=t4;i<=n;i++){
					if(a[i]-a[t2]<=d && a[i]-a[t2-1]>d){
						ans+=i+1-t1-1;
					}else if(a[i]-a[t2]>d)break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
