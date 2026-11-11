#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
int ans;
void dfs(int d,int l,int sum){
	if(d==m){
		ans=max(ans,sum);
		return;
	}
	if(l==n) return;
	for(int i=l+1;i<=n;i++){
		if(d==0) dfs(1,i,a[i]);
		else dfs(d+1,i,sum&a[i]);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	else{
		if(m==n){
			int ans=a[1];
			for(int i=2;i<=n;i++){
				ans=ans&a[i];
			}
			cout<<ans;
		}
		else{
			dfs(0,0,0);
			cout<<ans;
		}
	}
	return 0;
} 
