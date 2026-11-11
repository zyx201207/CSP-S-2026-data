#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N];
string s[N];
int n,m;
bool vis[N];
int aans=0;
void dfs(int deep,int ans){
	if(deep==m){
		aans=max(aans,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		dfs(deep+1,ans&a[i]);
		vis[i]=0;
	}
}
bool cmp(int a,int b){
	return a>b;
}
namespace pts1{
	void solve(){
		for(int i=1;i<=n;i++){ 
			vis[i]=1;
			dfs(1,a[i]);
			vis[i]=0; 
		}
		cout<<aans;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2000) pts1::solve();
	else {
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	} 
	return 0;
} 
/*
5 3
31 3 1 15 7
*/
