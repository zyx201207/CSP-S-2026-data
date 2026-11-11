#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010],diff[500010],dp[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	bool flag=1,flag2=1;
	int d=a[2]-a[1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]+1)
			flag=0;
	}
	
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=d){
			flag2=0;
		}
	}
	
	int sz4b=0,ans4b=0;
	if(flag2==1){
		for(int i=1;i<=n;i++){
			if(sz4b+d*i<=m){
				sz4b+=d*i;
				ans4b++;
			}
			else{
				break;
			}
		}
		cout<<ans4b<<endl;
		return 0;
	}
	
	int sz4a=0,ans4a=0;
	if(flag==1){
		for(int i=1;i<=n;i++){
			if(sz4a+i<=m){
				sz4a+=i;
//				cout<<sz4a<<endl;
				ans4a++;
			}
			else{
				break;
			}
		}
		cout<<ans4a<<endl;
		return 0;
	}
	
	sort(a+1,a+n+1);
	
	int ans=0;
	for(int i=2;i<=n;i++){
		queue<int> q;
//		memset(dp,0,sizeof dp);
		for(int j=1;j<i;j++){
			diff[j]=a[i]-a[j];
		}
//		for(int j=1;j<i;j++){
//			for(int k=m;k>=1;k--){
//				if(k>=diff[j]){
//					dp[k]=max(dp[k],dp[k-diff[j]]+1);
//				}
//			}
//		}
//		ans=max(ans,dp[m]+1);
		int sz=0,cnt=0;
		for(int j=i-1;j>=1;j--){
			if(sz+diff[j]<=m){
				q.push(diff[j]);
				sz+=diff[j];
				cnt++;
			}
			else{
				break;
			}
		}
		ans=max(ans,cnt+1);
	}
	cout<<ans<<endl;
	return 0;
} 
