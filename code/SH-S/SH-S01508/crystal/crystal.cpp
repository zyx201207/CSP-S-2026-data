#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,d,maxch,ex=0,ans=0,minst,cnt=0;
long long dp[500005][500005];
bool flag=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	d=a[2]-a[1];
	for(long long i=2;i<=n-1;i++){
		if(a[i+1]-a[i]!=d){
			flag=1;
			break;
		}
	}
	if(flag==0){//A&B
		if(m<d){
			cout<<"0";
			return 0;
		}
		maxch=(m-m%d)/d;
		for(long long i=1;i<=n;i++){
			ex+=i;
			ans++;
			if(ex>=maxch){
				maxch=ex-i;
				break;
			}
		}
		cout<<ans+1;
		return 0;
	}
	long long minn=a[n]-a[1]+1;
	for(long long i=1;i<=n-1;i++){
		for(long long j=i+1;j<=n;j++){
			dp[i][j]=a[j]-a[i];
			minn=min(minn,dp[i][j]);
		}
	}
	if(m<minn){
		cout<<"1";
		return 0;
	}
	for(long long i=2;i<=n;i++){
		minst=m+1;
		for(long long j=1;j<=n-i+1;j++){
			cnt=0;
			for(long long k=j;k<=j+i-2;k++){
				cnt+=dp[k][j+i-1];
			}
			minst=min(minst,cnt);
		}
		if(minst>m){
			cout<<i-1;
			return 0;
		}
	}
}
