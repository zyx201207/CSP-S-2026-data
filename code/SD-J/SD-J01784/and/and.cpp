#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans=-1,sum,maxx=-1;
bool f=1;
void dfs(int x,int k,int res){
	if(x>n&&k<m)return;
	if(k==m){
		ans=max(ans,res);
		return;
	}
	dfs(x+1,k,res);
	if(k==0)dfs(x+1,k+1,a[x]);
	else dfs(x+1,k+1,res&a[x]);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)sum=a[i];
		else sum&=a[i];
		maxx=max(maxx,a[i]);
		if(log2(a[i]+1)!=floor(log2(a[i]+1)))f=0;
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==n){
		cout<<sum;
		return 0;
	}
	if(f==1){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	dfs(1,0,-1);
	cout<<ans;
	return 0;
}
