#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int a[214514];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){	
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c!=0&&c<=6){
			for(int i=1;i<=n;i++){
				for(int j=i+2;j<=n;j++){
					int cnt=0;
					for(int k=i+1;k<j;k++){
						if(a[j]-a[i]>d&&a[j]-a[k]<=d&&a[k]-a[i]<=d){
							cnt++;
						}
					}
					if(cnt==2)ans++;
				}
			}
			cout<<ans<<'\n';
		}else{
			for(int i=1;i<=n;i++){
				int pos=upper_bound(a+1,a+n+1,a[i]+d)-a;
				for(int j=pos;j<=n;j++){
					int cnt=0;
//					for(int k=i+1;k<j;k++){
//						if(a[j]-d<=a[k]&&a[k]<=d+a[i]){
//							cnt++;
//							cout<<k<<' ';
//						}
//					}
					int l=lower_bound(a+i+1,a+j,a[j]-d)-a;
					int r=upper_bound(a+i+1,a+j,a[i]+d)-a-1;
					l=max(i+1,l),r=min(j-1,r);
//					cout<<i<<' '<<j<<' '<<l<<' '<<r<<'\n';
					if(r-l+1==2)ans++;
				}
			}
			cout<<ans<<'\n';
		}
		
		
			
	}
	return 0;
}



