#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d,a[2000100],p[2000100],ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			int j=i+1;
			for(;j<=n;j++){
				if(a[j]-a[i]>d)p[j-1]=j-1-i;
			}
		}
		int t=a[2]-a[1],w=1;
		for(int i=2;i<n;i++){
			if(a[i+1]-a[i]!=t){
				w=0;
				break;
			}
		}
		if(w==1){
			int b=d/t;
			for(int i=1;i<=n;i++){
				if(i+2*b-1<=n)ans++;
			}
			cout<<ans<<endl;
			continue;
		}
		else{
			cout<<0<<endl;
		}
//		for(int l=1;l<n;l++){
//			for(int r=l+1;r<=n;r++){
//				memset(dp,0x3f,sizeof(dp));
//				
//				for(int i=l;i<r;i++){
//					for(int j=max(l,i-p[i]);j<i;j++){
//						dp[i]=min(dp[j],dp[i])+1;
//						
//					}
//				}
//			}
//		}
	}
}
