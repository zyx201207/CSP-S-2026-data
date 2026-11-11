#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,m;
int a[N];
int dp[N];
int ans;
bool check(int k){
	int s=0;
	int cnt=0;
	int mi=dp[k];
	if(mi<=m) return 1;
	for(int i=k+1;i<=n;i++){
		s+=(a[i]-a[i-1])*cnt+a[i]-a[++cnt];
		mi=min(mi,dp[i]-s);
	}
	if(mi<=m) return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	dp[1]=0;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	int l=1,r=n;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(check(mid)){
			l=mid+1;
			ans=max(ans,mid);
		}else{
			r=mid-1;
		}
	}
	if(check(l)) ans=max(ans,l);
	cout<<ans;
	return 0;
}
