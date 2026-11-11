#include <bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
int maxn=0;
void dfs(int step,int sum,int ans){
	if(step>n&&sum==m){
		maxn=max(maxn,ans);
		cout<<maxn<<" ";
		return;
	}
	if(step>n&&sum!=m){
		return;
	}
	if(step!=n&&sum==m){
		maxn=max(maxn,ans);
		cout<<maxn<<" ";
		return;
	}
	if(sum==0){
		dfs(step+1,sum+1,a[step]);
		dfs(step+1,sum,0);
	}
	else{
		dfs(step+1,sum+1,ans&a[step]);
		dfs(step+1,sum,ans);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;++i)ans&=a[i];
		cout<<ans;
		return 0;
	} 
	if(m==2){
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		int ans=0;
		for(int i=1;i<=n;++i){
			if(i==1){
				int cnt=a[2];
				for(int j=3;j<=n;++j)cnt&=a[j]; 
				ans=max(ans,cnt);
			}
			else{
				int cnt=0;
				for(int j=1;j<=n;++j){
					if(j==i)continue;
					cnt&=a[j];
					cout<<cnt<<" ";
				}
				ans=max(ans,cnt);
			}
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<maxn;
	return 0; 
}
