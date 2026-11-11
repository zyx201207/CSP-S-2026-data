#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int C,n,m,a[N],dis[N],dp[N],l[N],r[N];
void solve(){
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1){
		cout<<0<<'\n';
		return;
	}
	if(C==11||C==12){
		int x=m/(a[2]-a[1]);
		if(x<=1||2*x>n){
			cout<<0<<'\n';
			return;
		}
		cout<<n-2*x+1<<'\n';
		return;
	}
	for(int i=1;i<=n;i++)dis[i]=dp[i]=0;
	for(int i=1,j=1,k=0;i<=n;i++){
		while(j<i&&a[i]-a[j]>m)j++;
		while(k<n&&a[k+1]-a[i]<=m)k++;
		l[i]=j;r[i]=k;
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			dp[i]=1;
			for(int j=i+1;j<=n;j++){
				int x=max(l[j],i);
				dis[j]=dis[x]+1;
				dp[j]=dp[x];
				if(x+2<j&&dis[x+2]==dis[x])dp[j]=3;
				else if(x+1<j&&dis[x+1]==dis[x])dp[j]+=dp[x+1];
				if(dp[j]==2)ans++;
			}
		}
		cout<<ans<<'\n';
		return;
	}
	if(a[n]-a[1]<=2*m){
		for(int i=1;i<=n;i++){
			int x=r[i];
			ans+=r[max(x-1,i)]-r[max(x-2,i)];
		}
		cout<<ans<<'\n';
		return;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;cin>>C>>T;
	while(T--)solve();
	return 0;
}
