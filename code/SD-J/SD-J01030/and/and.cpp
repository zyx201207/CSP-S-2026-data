#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5; 
int n,m;
long long mx,a[N];
void dfs(long long ans,int i,int cnt){
	if(cnt==m){
		mx=max(mx,ans);
		return ;
	}
	if(i==n) return ;
	if(cnt==0) dfs(a[i+1],i+1,cnt+1);
	else{
		long long t=ans;
		dfs(t&a[i+1],i+1,cnt+1);
	}
	dfs(ans,i+1,cnt);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,0);
	cout<<mx;
	return 0;
} 
