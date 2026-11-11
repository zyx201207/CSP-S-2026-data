#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
stack<int>stk;int ans[500005];bool vis[500005];
void solve(int l,int r){
	for(int i=1;i<=m;i++)vis[i]=0;
	for(int i=l;i<=r;i++){
//		cout<<i<<'\n';
		if(vis[a[i]])while(stk.top()!=a[i])vis[stk.top()]=0,stk.pop();
		else stk.push(a[i]),vis[a[i]]=1;
	}
	while(!stk.empty()){
		ans[stk.top()]++;
		stk.pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)solve(i,n);
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';cout<<'\n';
	return 0;
}

