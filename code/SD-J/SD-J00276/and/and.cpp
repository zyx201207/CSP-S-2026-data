#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans;
void dfs(long long x,long long sum,long long cnt){
	if(x>n){
		//cout<<sum<<' ';
		if(sum!=0xffffffffffffffff && cnt==m){
			ans=max(ans,sum);
		}
		return;
	}
	dfs(x+1,sum&a[x],cnt+1);
	dfs(x+1,sum,cnt);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0xffffffffffffffff,0);
	cout<<ans;
	return 0;
}

