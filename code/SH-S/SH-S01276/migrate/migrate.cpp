#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N=2e6+5;

int c,t,n,d;
int x[N],p[N],pp[N],temp[N];
int dp[N],cnt[N];
bool used[N];

signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i],pp[i]=0,used[i]=0;
		for(int i=1;i<=n;i++) {
			int l=1,r=i,res=i;
			while(l<=r) {
				int mid=(l+r)>>1;
				if(x[i]-x[mid]>d) l=mid+1;
				else r=mid-1,res=mid;
			}p[i]=res;
			l=i,r=n,res=i;
			while(l<=r) {
				int mid=(l+r)>>1;
				if(x[mid]-x[i]>d) r=mid-1;
				else l=mid+1,res=mid;
			}
			pp[i]=res;
		}
		int ans=0,last=0;
		for(int i=1;i<=n;i++) {
			dp[i]=0;cnt[i]=1;
			if(used[i]) continue;
			for(int j=i+1;j<=n;j++) {
				if(p[j]==j) break;
				dp[j]=dp[max(p[j],i)]+1;
				int pos=max(p[j],i);
				cnt[j]=cnt[pos];
				if(dp[pos+1]==dp[pos]) cnt[j]+=cnt[pos+1];
				if(dp[pos+2]==dp[pos]&&pos+2<=j) cnt[j]+=cnt[pos+2];
				if(cnt[j]==2) {
					ans++;
				}
			}
		}cout<<ans<<'\n';
	}
	return 0;
}
