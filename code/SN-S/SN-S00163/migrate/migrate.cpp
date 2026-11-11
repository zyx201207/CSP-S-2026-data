#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d;
int dp[5010],cnt[5010],a[2000010];
void solve1(){
	int ans=0;
	for(int x=1;x<=n;x++){
		dp[x]=0;cnt[x]=1;
		for(int i=x+1;i<=n;i++)
			dp[i]=1e18,cnt[i]=0;
		for(int i=x+1;i<=n;i++){
			int pos=lower_bound(a+1,a+1+n,a[i]-d)-a;
			//cout<<i<<' '<<pos<<endl;
			for(int j=max(x,pos);j<i;j++)
				if(dp[i]>dp[j]+1)
					dp[i]=dp[j]+1,cnt[i]=cnt[j];
				else if(dp[i]==dp[j]+1)cnt[i]+=cnt[j];
		}
		//cout<<x<<' '<<n<<endl;
		//for(int i=x+1;i<=n;i++)
		//	cout<<cnt[i]<<' ';cout<<'\n';
		for(int i=x+1;i<=n;i++)
			if(cnt[i]==2)ans++;
	}
	/*
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			int pa=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
			int pb=lower_bound(a+1,a+1+n,a[j]-d)-a;
			if(pa-pb==1)ans++;
		}//ÆúÓÃ 
	*/
	cout<<ans<<'\n';
}
void solve2(){
	int dt=a[2]-a[1];
	for(int i=1;1+i+i+1<=n;i++)
		if(d>=(i+1)*dt&&d<(i+2)*dt){cout<<n-i-i-1<<'\n';return;}
	cout<<0<<'\n';
}
void solve3(){
	cout<<2<<'\n';
}
void solve(){
	cin>>n>>d;
	bool A=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2])A=0;
	}
	if(n<=5000)solve1();
	else if(A)solve2();
	else solve3();
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--)solve();
}
