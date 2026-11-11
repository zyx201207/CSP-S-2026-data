#include<bits/stdc++.h>
const int N=2e5+10;
using namespace std;
int n,m,a[N],sum;
void dfs(int x,int s,int s2){
	if(x<1){
		if(s==0) sum=max(sum,s2);
		return ;
	}
	dfs(x-1,s-1,s2&a[x]);
	dfs(x-1,s,s2);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dfs(n-1,m,a[n]);
	cout<<sum;
	return 0;
}
