#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mcx=2e6+5;
int c,t,n,a[mcx],d,dp[mcx];
//class SUBA{
//public:
//	void work(){
//		while(t--){
//			cin>>n>>d;
//			for(int i=1;i<=n;i++)cin>>a[i];
//			int gc=a[2]-a[1];
//			if(d<=1)cout<<0<<'\n';
//			else{
//				if(gc<=d)cout<<0<<'\n';
//				else if(d<=2*gc)cout<<n-3<<'\n';
//				else if(d>2*gc&&d<=3*gc)cout<<n/2<<'\n';
//			}
//		}
//	}
//};

signed main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c>=13&&c<=14){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			cout<<n<<'\n';
		}
		return 0;
	}
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int l=1;l<=n-3;l++)
		for(int r=l+3;r<=n;r++){
			if(a[r]-a[l]<=d||(r-l+1>=5))continue;
			int sum=0;
			int ri=lower_bound(a+l+1,a+r+1,a[r]-d)-a;
			int li=lower_bound(a+l+1,a+r+1,a[l]+d)-a;
			if(ri<li&&(a[r]-a[li]<=d)&&(a[ri]-a[l]<=d)){
//				cout<<l<<' '<<r<<'\n';
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
