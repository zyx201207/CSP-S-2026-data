#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ans;
int n,m;
int a[100005],b[100005];
void dfs(int dep,int x,int cnt){
	if(cnt==m){
		ans=max(ans,x);
		return;
	}
	if(dep>n)return;
	if(n-dep+1+cnt<m)return;
	if(int(x&a[dep])>ans)
		dfs(dep+1,x&a[dep],cnt+1);
	if(n-dep+1+cnt>m)
		dfs(dep+1,x,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>n>>m;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n>2000&&n<=200005){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m];
		return 0;
	}
	dfs(1,pow(2,30)-1,0);
	cout<<ans;
	return 0;
}
