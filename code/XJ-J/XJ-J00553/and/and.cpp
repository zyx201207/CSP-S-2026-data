#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N],maxn,v[N];
int ch(int x,int ans){
	return ans^a[x];
}
void dfs(int x,int cnt,int ans){
	if(cnt==m){
		maxn=max(maxn,ans);
		return ;
	}
	if(x>=n){
		return ;
	}
	int c;
	if(!v[x]){
		c=ch(x,ans);
		v[x]=1;
	}
	if(c<ans){
		return ;
	}
	dfs(x+1,cnt+1,c);
	dfs(x+1,cnt,ans);
	v[x]=0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	dfs(1,0,0);
	cout<<maxn;
	return 0;
}
