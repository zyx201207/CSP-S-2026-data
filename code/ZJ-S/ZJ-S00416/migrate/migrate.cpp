#include<bits/stdc++.h>
#define ll long long
#define N 2000009
using namespace std;
int cll,T;
ll read(){
	char ch=getchar();
	ll wz=0,sg=1;
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-'){
		sg=-1;ch=getchar();
	}
	while(isdigit(ch)){
		wz=wz*10+(ch-48);
		ch=getchar();
	}
	return wz*sg;
}
ll a[N],st[5009][15];
int lg[5009];
int lb[5009][5009];
int opt[5009][5009];
ll n,d;
ll quest(int l,int r){
	int ly=lg[r-l+1];
	return max(st[l][ly],st[r-(1<<ly)+1][ly]);
}
int fndlq(int l,int r,ll x){
	int lo=l,ro=r,ans=l-1;
	while(lo<=ro){
		
		int mi=(lo+ro)>>1;
		if(a[mi]>=x)ans=mi,ro=mi-1;
		else lo=mi+1;
	}
	return ans;
}
int fndrq(int l,int r,ll x){
	int lo=l,ro=r,ans=l-1;
	while(lo<=ro){
		int mi=(lo+ro)>>1;
		if(a[mi]<=x)ans=mi,lo=mi+1;
		else ro=mi-1;
	}
	return ans;
}
int curl[5009],curr[5009];
int dp[5009][5009];
unsigned cnt[5009][5009];
void sub1(){
	int ans=0;
	int cur=1;
	a[0]=-2e18;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j]=0x3f3f3f3f,cnt[i][j]=0;
	for(int i=1;i<=n;i++)dp[i][i]=0,cnt[i][i]=1;
	for(int i=1;i<n;i++)
		if(a[i+1]-a[i]<=d)dp[i][i+1]=1,cnt[i][i+1]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-i+1;j++)
			for(int k=i+1;k<i+j-1;k++){
				if(a[k]-a[i]<=d&&a[j]-a[k]<=d){
					if(dp[i][k]+dp[k][j]<dp[i][j]){
						dp[i][j]=dp[i][k]+dp[k][j];
						cnt[i][j]=cnt[i][k]*cnt[k][j];
					}
					else if(dp[i][k]+dp[k][j]==dp[i][j]){
						dp[i][j]=dp[i][k]+dp[k][j];
						cnt[i][j]+=cnt[i][k]*cnt[k][j];
					}
					cout<<a[i]<<' '<<a[j]<<' '<<a[k]<<'\n';
					cout<<dp[i][j]<<cnt[i][j]<<'\n';
				}
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cout<<cnt[i][j]<<(j==n?'\n':' ');
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(cnt[i][j]==2)ans++;
	cout<<ans<<'\n';
	return;
}
void work(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=n;i>=1;i--)a[i]-=a[1];
	if(cll<=10)sub1();
	for(int i=1;i<=n;i++)a[i]=0;
	return;
}
int main(){
	freopen("migrate1.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>cll>>T;
	while(T--)work();
	return 0;
}
