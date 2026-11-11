#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
#define lowbit(x) ((x)&-(x))
using namespace std;
const int N=2e6,N2=5e3;
int c,t,n,d,a[N+5],len[N2+5][N2+5],dp[N2+5][N2+5],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	for(;t--;){
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=len[i][j]=0;
			}
		}
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c>=11&&c<=12){
			int _=a[2]-a[1];
			d/=_;
			if(d<=1){
				cout<<"0\n";
			}
			else{
				cout<<max(0ll,n-2*d+1)<<"\n";
			}
			continue;
		}
		int _=1;
		for(int j=1;j<=n;j++){
			int l=lower_bound(a+_,a+j+1,a[j]-d)-a,r=j;
			dp[j][j]=1;
			if(l==j) _=j;
			for(int i=_;i<j;i++){
				if(l<i) l++;
				len[i][j]=len[i][l]+1;
				if(j-l+1<=2||len[i][l+2]>len[i][j]-1){
					dp[i][j]=dp[i][l];
					if(l<j&&len[i][l+1]<=len[i][j]-1){
						dp[i][j]+=dp[i][l+1];
					}
				}
				else{
					dp[i][j]=3;
				}
				if(dp[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
