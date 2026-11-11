#include<bits/stdc++.h>
using namespace std;
bool vis[200005];
long long n,m,a[200005];
long long maxn=-1;
void dfs(long long t,long long cnt){
	if(t==m){
		maxn=max(maxn,cnt);
		return;
	}for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			dfs(t+1,cnt&a[i]);
			vis[i]=false;
		}
	}return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		vis[i]=true;
		dfs(1,a[i]);
		vis[i]=false;
	}cout<<maxn;
	return 0;
}
