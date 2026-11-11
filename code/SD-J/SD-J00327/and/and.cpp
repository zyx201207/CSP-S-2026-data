#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];	
int n,m;
long long ans=0,st=(long long)pow(2,31)-1;
void dfs(int x,int k,long long sum){
	if(k==m && sum!=st){
		ans=max(ans,sum);
		return;
	}
	if(x==n+1) return;
	dfs(x+1,k,sum);
	dfs(x+1,k+1,sum&a[x]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,st);
	cout<<ans;
	return 0;
} 
