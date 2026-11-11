#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,ans;
int a[N],b[N];
void dfs(int now,int idx){
	if(idx>n+1) return;
	if(now==m+1){
		int res=b[1];
		for(int i=2;i<=m;i++) res&=b[i];
		ans=max(ans,res);
		return;
	}
	b[now]=a[idx];
	dfs(now+1,idx+1);
	dfs(now,idx+1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<*max_element(a+1,a+n+1);
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<ans;
		return 0;
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}