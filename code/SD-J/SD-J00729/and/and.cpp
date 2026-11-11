#include <bits/stdc++.h>
#define int long long
using namespace std;
void suio(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void fio(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
}
const int N=2e5+5;
int n,m,a[N],maxn;
void dfs(int cur,int cnt,int val){
	if(cnt>=m){
		maxn=max(maxn,val);
		return ;
	}
	if(val<maxn){
		return ;
	}
	for (int i=cur+1;i<=n;i++){
		dfs(i,cnt+1,val&a[i]);
	}
}
signed main(){
	suio();
	fio();
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n-m+1;i++){
		dfs(i,1,a[i]);
	}
	cout<<maxn;
	return 0;
}
