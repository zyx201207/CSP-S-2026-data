#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=pow(2,31)-1;
int n,m,a[200005],dp[200005],ans,vis[200005],num[200005],cnt[35],fa,fb;
void dfs(int k,int p,int sum){
	if(sum<ans){
		return ;
	}
	if(k==m+1){
		ans=max(ans,sum);
		return ;
	}
	for(int i=p;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			num[k]=a[i];
			if(k==1){
				dfs(k+1,p+1,a[i]);
			}
			else{
				dfs(k+1,p+1,sum&a[i]);
			}
			vis[i]=0;       
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=2&&a[i]-a[i-1]!=1){
			fb=1;
		}
		int x=a[i],l=0;
		while(x){
			if(x%2==1){
				cnt[l]++;
			}
			else{
				fa=1;
			}
			x/=2;
			l++;
		}
	}
	for(int i=0;i<=30;i++){
		cout<<cnt[i]<<" ";
	}
	cout<<fa<<" "<<fb;
//	for(int i=33;i>=0;i--){
//		if(cnt[i]>=m){
//			ans+=pow(2,i);
//			i--;
//			while(cnt[i]>=m){
//				ans+=pow(2,i);
//				i--;
//			}
//		}
//	}
	
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	else if(m==n-1){
		int flag=0;
		for(int i=33;i>=0;i--){
			if(cnt[i]>=m){
				ans+=pow(2,i);
				flag=1;
			}
			else{
				if(flag==1){
					cout<<ans;
					return 0;
				}
			}
		}
	}
	else{
		dfs(1,1,a[1]);
	}
	cout<<ans;
	return 0;
}