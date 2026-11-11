#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int ans=INT_MIN;
int sum;
void dfs(int k,int sum,int idx){
	if(k==m){
		ans=max(ans,sum);
		return;
	}
	if(idx==n && k<m){
		return;
	}
	for(int i=idx+1;i<=n;i++){
		if(k==0){
			dfs(k+1,a[i],i);
		}else{
			dfs(k+1,sum&a[i],i);
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		sum=a[1];
		for(int i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
		return 0;
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
