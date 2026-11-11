#include <bits/stdc++.h>
using namespace std;
long long a[100100],n,ma,m;
void dfs(long long j,long long s,long long siz){
	if(siz>m) return;
	if(siz==m) ma=max(ma,s);
	for(int i=j+1;i<=n;i++){
		dfs(i,s&a[i],siz+1);
	}
}
int main(){
	freopen("and3.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n>>m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(i,a[i],1);
	}
	cout << ma;
	return 0;
}
