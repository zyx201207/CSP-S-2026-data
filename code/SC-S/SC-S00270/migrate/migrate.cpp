#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5,M=1005;
int c,t,n,a[N],sum,m,dp[M][M],b[N],cnt,su[N],ans;
void solve1(){
	ans=0;
	int x=a[2]-a[1];
	int y=m/x;
	for(int i=0;i<y;i++){
		x=(n-i)/y;
		ans+=x*(x-1)/2;
	}
	cout<<ans<<'\n';
}
void solve2(){
	ans=0;
	int r=1,mid1,mid2=1,s2=0,l=1,s1=0;
	while(1){
		r++;
		sum+=a[r]-a[r-1];
		if(sum>m){
			mid1=r-1;
			break;
		}
		s1=s2=sum;
	}
	r--;mid1=r;
	while(r<n){
		r++;
		s2+=a[r]-a[r-1];
		while(s2>m) s2=a[r]-a[++mid2];
		while(mid1-mid2<1){
			l++;
			s1=a[mid1]-a[l];
			while(s1<m) s1=a[++mid1]-a[l];
		}
		if(mid1-mid2==1) ans++;
		cout<<l<<" "<<r<<" "<<mid1<<" "<<mid2<<'\n';
	}
	cout<<ans<<'\n';
}
//void solve3(){
//	s[0]=1;
//	for(int i=1;i<=n;i++){
//		sum+=a[i];
//		s[i]=s[i-1];
//		if(sum>m) s[i]++,sum-=m,b[++cnt]=i;
//	}
//	for(int i=1;i<=n;i++){
//		if(s[i]>b[l]) l++;
//		r=l+1;
//		dp[i][i]=1;
//		for(int j=i+1;j<=n;j++){
//			if(s[j]>b[r]) r++,sum=0;
//			if(l==r) dp[i][j]=1,sum++;
//			
//		}
//	}
//}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;sum=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c==11||c==12) solve1();
		if(c==13||c==14) solve2();
		
	}
}