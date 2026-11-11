#include<bits/stdc++.h>
using namespace std;
const int N=2000+5;
int n,m,a[N],dp[N][N],ans;
void dfs(int step,int cnt,int sum){
	if(step==n+1&&cnt<m||n-step+1+cnt<m)return;
	if(cnt==m){
//		cout<<sum<<" ";
		ans=max(ans,sum);
		return;
	}
//	cout<<step<<" "<<sum<<" "<<cnt<<'\n';
	if(cnt==0){
		dfs(step+1,cnt+1,a[step]);
		dfs(step+1,cnt,sum);
	}else{
		dfs(step+1,cnt+1,sum&a[step]);
		dfs(step+1,cnt,sum);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1,0,0);
		cout<<ans;
	}else{
		if(m==1){
			int mx=a[1];
			for(int i=2;i<=n;++i){
				mx=max(mx,a[i]);
			}
			cout<<mx;
		}else if(m==n){
			int all_sum=a[1];
			for(int i=2;i<=n;++i){
				all_sum&=a[i];
			}
			cout<<all_sum;
		}else if(m==2){
			for(int i=1;i<=n;++i){
				for(int j=i+1;j<=n;++j){
					ans=max(ans,a[i]&a[j]);
				}
			}
			cout<<ans;
		}else{
			sort(a+1,a+1+n,greater<int>());
			ans=a[1];
			for(int i=2;i<=m;++i){
				ans&=a[i];
			}
			cout<<ans;
		}
	}
	return 0;
}
//55pts
/*
4 2
3 15 12 12
*/