#include<bits/stdc++.h>
#define lowbit ((x)&(-x))
#define ls(u) ((u)<<1)
#define rs(u) (((u)<<1)|1)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int N=5005,INF=0x3f3f3f3f,mod=998244353;
const double eps=1e-9;

ll n,a[N],dp[N][N],cnt[N][N],d[N],q,f,ans;
void solve(){
	cin>>n>>q;f=1,ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2)d[i-1]=a[i]-a[i-1];
		if(i>2&&a[i]-a[i-1]!=d[1])f=0;
	}
	if(f){
		q=q/d[1];
		if(q<=1)cout<<0<<"\n";
		else cout<<max(0ll,n-2*q+1)<<"\n";
		return;
	}
	memset(dp,0x3f,sizeof(dp));memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++){
		dp[i][i]=0,cnt[i][i]=1;
		for(int j=i+1;j<=n;j++){
			for(int k=j-1;k>=i&&a[j]-a[k]<=q;k--){
				if(dp[i][j]>dp[i][k]+1)cnt[i][j]=cnt[i][k],dp[i][j]=dp[i][k]+1;
				else if(dp[i][j]==dp[i][k]+1)cnt[i][j]+=cnt[i][k];
			}
		}
	}
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ans+=(cnt[i][j]==2);
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
