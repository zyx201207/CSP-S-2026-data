#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int a[N],cnt[N];
int ans=-1,n,m;
void dfs(int c,int sum){
	if(sum>m){
		return;
	}
	if(c>n&&sum<m){
		return;
	}
	if(c>n&&sum==m){
		int aa=cnt[1];
		for(int i=2;i<=sum;i++){
			aa=aa&cnt[i];
		}
		ans=max(ans,aa);
		return ;
	}
	dfs(c+1,sum);
	cnt[sum+1]=a[c];
	dfs(c+1,sum+1);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}

