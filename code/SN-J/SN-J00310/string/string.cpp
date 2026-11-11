#include<bits/stdc++.h> 
using namespace std;
using ll = long long;
int n;
ll ans = 0;
struct node{int u;char s;}a[200008];
void dfs(int l,int r){
	if(l >= r) return;
	if(a[l].s != a[r].s){
		ans += min(a[l].u,a[r].u);
		int rc = abs(a[l].u-a[r].u);
		a[l].u -= rc;
		a[r].u -= rc;
		if(a[l].u > a[r].u)	r--;
		else if((a[l].u < a[r].u)) l++;
		else if((a[l].u = a[r].u)) l++,r--;
	}
	else{
		int rc = abs(a[l].u-a[r].u);
		a[l].u -= rc;
		a[r].u -= rc;
		if(a[l].u > a[r].u)	r--;
		else if((a[l].u < a[r].u)) l++;
		else if((a[l].u = a[r].u)) l++,r--;
	}
	dfs(l,r);
	return;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i].u);
		cin >> a[i].s;
	}
	dfs(1,n);
	printf("%d",ans);
	return 0;
}
