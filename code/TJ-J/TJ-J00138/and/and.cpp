#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans=0;
void dfs(int id,int cnt,int sum){
	if(id==n+1){
		if(cnt==m) ans=max(ans,sum);
		return;
	}
	if(cnt==0){
		dfs(id+1,cnt,sum);
		dfs(id+1,cnt+1,a[id]);
	}
	else{
		dfs(id+1,cnt,sum);
		dfs(id+1,cnt+1,sum&a[id]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}
	else{
		if(m==n){
			ans=a[1];
			for(int i=2;i<=n;i++){
				ans=ans&a[i];
			}
			cout<<ans;
			return 0;
		}
		else if(m==1){
			for(int i=1;i<=n;i++){
				ans=max(ans,a[i]);
			}
			cout<<ans;
			return 0;
		}
		else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(i!=j){
						ans=max(ans,a[i]&a[j]);
					}
				}
			}
			cout<<ans;
			return 0;
		}
		else{
			sort(a+1,a+n+1);
			ans=a[n];
			for(int i=n;i>=n-m+1;i++){
				ans=ans&a[i];
			}
			cout<<ans;
		}
	}
	
	return 0;
}
