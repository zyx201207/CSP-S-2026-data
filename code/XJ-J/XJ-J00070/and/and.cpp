#include<iostream>
#include<cstdio>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
long long ans=0;
vector<long long> a,vis;
int dfs(int sy,long long hui,int dw){
	if(sy==0){
		ans=max(ans,hui);
		return 0;
	}
	for(int i=dw;i<a.size();i++){
		dfs(sy-1,hui&a[i],i+1);
	}
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	a.resize(n);
	vis.resize(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
		vis[i]=0;
	}
	for(int i=0;i<n;i++){
		dfs(m-1,a[i],i+1);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
