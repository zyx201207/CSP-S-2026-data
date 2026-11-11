#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7;
const int N=2e6+10;
auto getmax=[](auto &a,auto b){a=max(a,b);};
auto getmin=[](auto &a,auto b){a=min(a,b);};

int c,T,n,pre[N],nxt[N],dp[N],sum[N];
ll d,a[N],ans;
void solve(int l,int r){
	for(int i=l; i<=r; i++){
		fill(nxt+i,nxt+r+1,0);
		for(int j=i,k=j; j<r; ){		
			while(k<=r&&a[k]-a[j]<=d) k++;
			nxt[j+1]=k, j=k-1;	
		}
		sum[i-1]=0, sum[i]=1;
		for(int j=i+1; j<=r; j=nxt[j]){
			for(int k=j; k<nxt[j]; k++){
				dp[k]=sum[j-1]-sum[max(pre[k],i-1)];
				sum[k]=sum[k-1]+dp[k];
				if(dp[k]==2) ans++;
			}
		}
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>c>>T;
	while(T--){
		cin>>n>>d; ans=0;
		for(int i=1; i<=n; i++) cin>>a[i];
		for(int i=1,j=1; i<=n; i++){
			while(j<i&&a[i]-a[j]>d) j++;
			pre[i]=j-1;
		}
		
		int lst=1;
		for(int i=1; i<=n-1; i++)
			if(a[i+1]-a[i]>d) solve(lst,i), lst=i+1;
		solve(lst,n);
		
		cout<<ans<<endl;
	}
	
	return 0;
}