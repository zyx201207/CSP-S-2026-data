#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N=2e6+10,P=998244353;
int a[N],f[N],dp[N],s[N],b[N];
void slove2(){
	int n,d,j=1,ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		while(j<n&&a[j+1]-a[i]<=d) j++;
		f[i]=j;
	}
	if(f[1]==n){
		cout<<"0\n";
		return;
	}
	j=n;
	for(int i=n;i>=1;i--){
		while(j>1&&a[i]-a[j-1]<=d) j--;
		b[j]++;
	}
	for(int i=1;i<=n;i++) ans+=b[f[i]-1];
	cout<<ans<<'\n';
	for(int i=0;i<=n;i++) b[i]=0;
}
void slove(){
	int n,d,ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int l=1;l<n;l++){
		int j=l,y=l-1,x=l;
		f[l]=0;
		for(int i=l+1;i<=n;i++){
			while(a[i]-a[j]>d) j++;
			if(i==j) f[i]=1e18;
			else f[i]=f[j]+1;
		}
		dp[l]=1,s[l]=1,s[l-1]=0;
		for(int i=l+1;i<=n;i++){
			if(f[i]>n) break;
			dp[i]=0;
			while(y<i&&f[y+1]<f[i]) y++;
			while(a[i]-a[x]>d) x++;
			dp[i]=s[y]-s[x-1];
			if(dp[i]==2) ans++;
			if(dp[i]>2) dp[i]=3;
			s[i]=s[i-1]+dp[i];
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		if(c<=14&&c>=13) slove2();
		else slove();
	}
	return 0;
}
//CSP-S2026 rp++
//40pts 16:30
//48pts 17:45
