#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,m,a[N],dp[N][32],p[32]={1},ans=INT_MIN,fa=1,fb=1,maxx=INT_MIN,vis[N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(),cout.tie();
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<32;i++)p[i]=p[i-1]*2;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		int c=a[i];
		for(int j=31;j>=0;j--){
			if(c>=p[j]){
				dp[i][j]=dp[i-1][j]+1;
				c-=p[j];
			}else dp[i][j]=dp[i-1][j];
		}
		if(fa){
			int b=0;
			for(int j=0;j<32;j++){
				if(a[i]==p[j]-1){
					b=1;
					break;
				}
			}
			fa=b;
		}
		if(a[i]!=i-1)fb=0;
	}
	if(m==1){
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}else if(m==n){
		ans=p[31]-1;
		for(int i=1;i<=n;i++)ans=ans&a[i];
		cout<<ans;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
		}
		cout<<ans;
		return 0;
	}else if(fa){
		sort(a+1,a+1+n);
		ans=p[31]-1;
		for(int i=n;i>n-m;i--)ans=ans&a[i];
		cout<<ans;
		return 0;
	}else if(fb){
		ans=p[31]-1;
		sort(a+1,a+1+n);
		for(int i=n;i>n-m;i--)ans=ans&a[i];
		cout<<ans;
		return 0;
	}else if(m==n-1){
		for(int i=1;i<=n;i++){
			int sum=0;
			for(int j=0;j<32;j++)if(dp[i-1][j]+dp[n][j]-dp[i][j]==m)sum+=p[j];
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}else if(maxx<=4){
		sort(a+1,a+1+n);
		int b[5];
		for(int i=1;i<=n;i++)b[a[i]]++;
		if(b[4]>=m)cout<<4;
		else if(b[3]>=m)cout<<3;
		else if(b[2]+b[3]>=m)cout<<2;
		else if(b[1]+b[3]>=m)cout<<1;
		else cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=m;i--){
		int sum=INT_MAX;
		for(int j=i;j>i-m;j--)sum&=a[j];
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
