#include<bits/stdc++.h>
using namespace std;
#define For(i ,x ,y) for(int i = x; i <= y; ++ i)
#define Down(i ,x ,y) for(int i = x; i >= y; -- i)
#define int long long
int n ,m ,a[210000] ,f[210000] ,t ,maxn;
void dfs(int w ,int s ,int l){
	if(s == m){
		maxn = max(maxn ,w);
		return ;
	}
	For(i ,l + 1 ,n){
		dfs(w & a[i] ,s + 1 ,i);
	}
}
signed main(){
	freopen("and.in" ,"r" ,stdin);
	freopen("and.out" ,"w" ,stdout);
	cin >> n >> m;
	For(i ,1 ,n) cin >> a[i];
	if(m == n){
		t = a[1];
		For(i ,2 ,n) t &= a[i];
		cout << t;
		return 0;
	}
	For(i ,1 ,n - m + 1){
		dfs(a[i] ,1 ,i);
	}
	cout << maxn;
}