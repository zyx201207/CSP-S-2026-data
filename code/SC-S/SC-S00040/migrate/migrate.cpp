#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e6+60;
int c,t;
int a[MAXN];
int ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c;
	if(c>=11&&c<=12){
		cin>>t;
		while(t--){
			int n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int num=a[2]-a[1];
			int tag=n/d;
			if(num>=d){
				cout<<0<<endl;
			}else{
				cout<<max(0ll,n-d/num*2+1)<<endl;
			}
		}
	}
	if(c>=13&&c<=14){
		cin>>t;
		while(t--){
			ans=0;
			int n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int l=a[n]-d,r=a[1]+d;
			int ll=upper_bound(a+1,a+1+n,r)-a,rr=lower_bound(a+1,a+1+n,l)-a;
			rr--;
			for(int i=1;i<=rr;i++){
				ll=upper_bound(a+1,a+1+n,a[i]+d)-a;
				ans+=n-ll+1;
			}
			cout<<ans<<endl;
		}
	}
}