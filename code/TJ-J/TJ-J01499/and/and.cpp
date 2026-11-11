#include <bits/stdc++.h>
using namespace std;
int n;
long long maxs=0;
long long a[200005];
void dfs(int m,long long x,long long  p){
	if (m<=0){
		return;
	}
	if (n<p){
		return;
	} 
	x=x&a[p];
	if (x>=maxs){
		maxs=x;
	}
	dfs(m-1,x,p+1);
	return;
}
int main (){
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	int m; 
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	for (int i=0;i<=n+1;i++){
		dfs(m-1,a[i],i+1);
	}
	cout << maxs;
	return 0;
}

