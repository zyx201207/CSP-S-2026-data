#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N];


int k=0;
void dfs(int ans,int now,int cnt){
	if(cnt>=m){
		k=max(ans,k);
		return ;
	}
	if(now>n) return ;
	dfs(ans,now+1,cnt);
	dfs((cnt==0?a[now]:ans&a[now]),now+1,cnt+1);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1,0);
	cout<<k;
	return 0;
}

