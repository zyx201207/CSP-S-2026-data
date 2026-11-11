#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],ans,ans2,ma,sum;
void dfs(int u){
	if(u==m+1){
		ma=max(ma,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		sum&=a[i];
		dfs(u+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m) {
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==n-1){
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		for(int i=1;i<=n-1;i++){
			ans2&=a[i];
		}
		cout<<max(ans,ans2);
		return 0;
	}
	dfs(1);
	cout<<ma;
	return 0;
}

