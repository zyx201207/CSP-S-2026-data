#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
int n,m;
long long ans=0;
void dfs(int x,long long s,int d){
	if(x==m){
		ans=max(ans,s);
		return;
	}
	if(d>n) return;
	for(int i=d;i<=n;i++){
		dfs(x+1,(s==0?a[i]:s&a[i]),i+1);
		dfs(x,s,i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,1);
	cout<<ans;
	return 0;
}
