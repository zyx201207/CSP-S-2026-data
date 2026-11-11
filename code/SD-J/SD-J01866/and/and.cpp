#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m;
bool vis[N];
int a[N];
int dfs(int x,int b){
	if(x==0){
		return a[b];
	}
	int maxn=-1;
	for(int i=b+1;i<=n-x+1;i++){
		int aa=a[b]&dfs(x-1,i);
		if((x+1)==m){
			maxn=max(maxn,aa);
		}
		else{
			return aa;
		}
	}
	return maxn;
	
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxnnn=-1;
//	cout<<dfs(m-1,1);
	for(int i=1;i<=n-m+1;i++){
		maxnnn=max(maxnnn,dfs(m-1,i));
	}
	cout<<maxnnn;
	return 0;
}
