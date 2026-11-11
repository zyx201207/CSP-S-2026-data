#include<bits/stdc++.h>
using namespace std;
int a[200005];
int maxx=-1e9;
int n,m;
void dfs(int x,int sumt,int sumc,bool flag){
	if(x==n+1){
		if(sumc==m){
			maxx=max(maxx,sumt);
			return ;
		}else{
			return ;
		}
	}
	if(flag==0){
		 dfs(x+1,sumt+a[x],sumc+1,1);
		 dfs(x+1,sumt,sumc,0);
    }
    dfs(x+1,sumt&a[x],sumc+1,1);
	dfs(x+1,sumt,sumc,1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<maxx;
	return 0;
}
