#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int ans=-1;
void dfs(int d,int sum,int ne){
	if(!ne){
		ans=max(sum,ans);
		return;
	}
	if(n-d+1<ne&&n<d)return;
	if(sum==-1)dfs(d+1,a[d],ne-1);
	else dfs(d+1,sum&a[d],ne-1);
	dfs(d+1,sum,ne);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,-1,m);
	cout<<ans;
	return 0;
}
