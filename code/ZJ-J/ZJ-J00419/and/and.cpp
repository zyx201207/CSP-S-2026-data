#include<bits/stdc++.h>
using namespace std;
int n, m, a[200010], mx = INT_MIN;
int an(int x,int  y){
	int a[100010], b[100010], aa = 0, bb = 0;
	int c = 0;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	while(a != 0){
		a[++aa] = x%2;
		x/=2;
	}
	while(b!=0){
		b[++bb] = y%2;
		y/=2;
	}
	for(int i = max(aa, bb); i >= 1; i--){
		if(a[i] && b[i]) c = c*10 + 1;
		else c = c*10;
	}
	return c;
}
void dfs(int l, int f, int s){
	if(l >= m){
		mx = max(mx, f);
		return ;
	}
	for(int i = s; i <= n; i++){
		dfs(l+1,  an(f,a[i]), s+1);
		dfs(l, f, s+1);
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(1, 0, 1);
	cout << mx;
	return 0;
}

