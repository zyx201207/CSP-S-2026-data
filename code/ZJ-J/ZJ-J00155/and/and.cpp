#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
void dfs(int k,int d,int j) {
	if(d<=ans) return;
	if(k==m) {
		ans=d;
		return;
	}
	for(int i=j+1; i<n; i++)
		if(i<ans) return;
		else dfs(k+1,d&a[i],i);
}
bool cmp(int a,int b) {return a>b;}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<n; i++) cin>>a[i];
	sort(a,a+n,cmp);
	dfs(0,INT_MAX,-1);
	cout<<ans;
	return 0;
}