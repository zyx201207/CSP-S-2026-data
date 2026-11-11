#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5005],temp=-1,f[5005],ans[5005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int k=a[1];k<=a[n];k++){
		int sum=0;
		//cout<<"***"<<endl;
		for(int i=1;i<=n;i++){
			if(a[i]<=k) f[i]=k-a[i];
			else{
				//cout<<a[i]<<" "<<a[k]<<endl;
				f[i]=-1;
				sum++;
			}
		}
		sort(f+1,f+n+1);
		int dp[5005];
		memset(dp,-1,sizeof(dp));
		dp[0]=0;
		for(int i=sum;i<=n;i++){
			for(int j=m;j>f[i];j--){
				dp[j]=max(dp[j],dp[j-f[i]]+1);
			}
		}
		ans[k]=dp[n];
		memset(f,0,sizeof(f));
	}
	for(int i=a[1];i<=a[n];i++){
		temp=max(temp,ans[i]);
	}
	cout<<temp/2;
	return 0;
}