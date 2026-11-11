#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], mlast[300005], cnt[300005], ans[300005], vis[300005], vis2[300005];
void dfs(int u, int c){
	if(u > n){
		return ;
	}
	ans[a[u]] += c;
	if(u != mlast[a[u]]){
		vis[a[u]] = 1;
		dfs(mlast[a[u]] + 1, c);
		vis2[mlast[a[u]] + 1] = 1;
	}else{
		dfs(u + 1, c + 1);
		vis2[u + 1] = 1;
	}
}
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
	cin  >>  n  >>  m;
	for(int i = 1;i <= n;++i){
		cin  >>  a[i];
		mlast[a[i]] = i;
		cnt[a[i]]++;
	}
	for(int i = 1;i <= n;++i){
		if(vis[a[i]] == 1 || vis2[i] == 1){
			continue;
		}
		dfs(i, cnt[a[i]]);
	}
	for(int i = 1;i <=m ;++i){
		cout  <<  ans[i]  <<  " ";
	}
	return 0;
}
