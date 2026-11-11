#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e6+10;
const int mod=2e18+9;
int n,d,l,ans,c,T;
int x[N];
int s[N];
int dp[N];
int lmt[N];
int sum[N];
int sum2[N];

void solve1(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			lmt[j]=sum[j]=0;
		s[i]=0;lmt[0]=i;dp[i]=sum[i]=1;
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[j-1]>d)break;
			s[j]=s[lower_bound(x+i,x+j+1,x[j]-d)-x]+1;
			lmt[s[j]]=max(lmt[s[j]],j);
		}
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[j-1]>d)break;
			dp[j]=sum[lmt[s[j]-1]]-sum[lower_bound(x+i,x+j+1,x[j]-d)-x-1];
			sum[j]=sum[j-1]+dp[j];
			if(dp[j]==2)ans++;
		}
	}
}

void solve2(){
	for(int j=1;j<=n;j++)
		lmt[j]=sum[j]=0;
	s[1]=0;lmt[0]=1;dp[1]=sum[1]=1;
	for(int j=2;j<=n;j++){
		if(x[j]-x[j-1]>d)break;
		s[j]=s[lower_bound(x+1,x+j+1,x[j]-d)-x]+1;
		lmt[s[j]]=max(lmt[s[j]],j);
	}
	for(int j=2;j<=n;j++){
		if(x[j]-x[j-1]>d)break;
		dp[j]=sum[lmt[s[j]-1]]-sum[lower_bound(x+1,x+j+1,x[j]-d)-x-1];
		sum[j]=sum[j-1]+dp[j];
		sum2[j]=sum2[j-1]+(dp[j]==2);
	}
	for(int i=1;i<=n;i++)
		ans+=sum2[i];
}

void solve3(){
	x[n+1]=4e18;
	for(int i=1;i<=n;i++){
		if(x[n]<=x[i]+d)break;
		int j=upper_bound(x+i,x+n+1,x[i]+d)-x-1;
		if(j==i+1)continue;
		ans+=upper_bound(x+i,x+n+2,x[j-1]+d)-x-1;
		if(j-i>2)ans-=upper_bound(x+i,x+n+2,x[j-2]+d)-x-1;
		else ans-=j;
	}
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=0;l=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		if(c<=10)solve1();
		else if(c<=12)solve2();
		else if(c<=14)solve3();
		cout<<ans<<'\n';
	}
	return 0;
}

