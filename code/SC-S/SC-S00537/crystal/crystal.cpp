#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int maxn=5000+10;
const int INF=0x3f3f3f3f3f3f3f3f;
int n,m;
int a[maxn*100];
int c;
bool A;
int k;
int dp[maxn][maxn];
int ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	c=a[2]-a[1];
	A=true;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=c){
			A=false;
			break;
		}
	}
	if(A==true){
		k=m/c;
		for(int i=1;i<=n;i++){
			if(i*(i+1)/2>k){
				cout<<i<<endl;
				return 0;
			}
		}
	}
	ans=-INF;
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;i++) dp[i][i]=0;
	for(int len=2;len<=n;len++){
		for(int l=1;l<=n-len+1;l++){
			int r=l+len-1;
			dp[l][r]=dp[l+1][r]+a[r]-a[l];
			if(dp[l][r]<=m) ans=max(ans,r-l+1);
		}
	}
	cout<<ans<<endl;
	return 0;
}
//不辨真伪，勿论虚实