#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,x,maxn;
void dfs(long long i,long long k,long long sum){
	if(k==x){
	//	cout<<sum<<endl;
		maxn=max(maxn,sum);
		return ;
	}
	if(i>n) return ;

	dfs(i+1,k,sum);
	if(sum==0){
		dfs(i+1,k+1,a[i]);
	}
	else dfs(i+1,k+1,sum&a[i]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>x;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<maxn<<endl;
	return 0;
}
