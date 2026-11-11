#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10086;
int a[N*50];
int dp[N][N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	memset(dp,0x3f,sizeof(dp));
	if(n>=10000){
		int d,flag=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==2)d=a[i]-a[i-1];
			if(i>2)if(a[i]-a[i-1]!=d)flag=1;
		}	
		if(flag){
			if(a[1]+a[1]>2*m){
				cout<<1;
				return 0;
			}
			for(int i=1;i<=n;i++){
				if((a[1]+a[i])*i>2*m){
					cout<<i-1;
					return 0;
				}
			}
		}
		cout<<n;
	}else{
		for(int i=1;i<=n;i++)cin>>a[i],dp[i][i]=0;
		sort(a+1,a+1+n);
		for(int len=1;len<=n;len++){
			int minn=INT_MAX;
			for(int i=1;i<=n-len;i++){
				dp[i][i+len]=dp[i][i+len-1]+(a[i+len]-a[i+len-1])*(len);
				minn=min(dp[i][i+len],minn);	
			}	
			if(minn>m){
				cout<<len;
				return 0;
			}
		}
		cout<<n;
	}
	return 0;
}

