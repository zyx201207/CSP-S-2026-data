#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans;
void dfs(int cnt,int idx,int x){
	if(cnt==m){
		ans=max(x,ans);
		return;
	}
	if(n-idx+1<m-cnt) return;
	if(x<ans&&x!=-1) return;
	for(int i=idx;i<=n;i++){
		dfs(cnt+1,i+1,x==-1?a[i]:x&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans<<'\n';
		return 0;
	}
	if(m==1){
		int mx=a[1];
		for(int i=2;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx<<'\n';
		return 0;
	}
	dfs(0,1,-1);
	cout<<ans<<'\n';
	return 0;
}
