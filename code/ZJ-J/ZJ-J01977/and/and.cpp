#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e3+5;
int n,m,a[N],ans=-1e9;

void dfs(int x,int cnt,int sum){
	if(x>n){
		if(cnt==m) ans=max(ans,sum);
		return;
	}
	dfs(x+1,cnt,sum);
	if(!cnt) dfs(x+1,cnt+1,a[x]);
	else dfs(x+1,cnt+1,sum&a[x]);
}

signed main(){
//	freopen("and3.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){dfs(1,0,0);cout<<ans;}
	else if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
	}
	else if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++) ans=(ans&a[i]);
		cout<<ans;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
//	else if(m==n-1){
//		
//	}
	return 0;
}
