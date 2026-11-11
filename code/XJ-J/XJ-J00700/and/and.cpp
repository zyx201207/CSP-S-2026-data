#include<bits/stdc++.h>
using namespace std;
int n,m,ans=INT_MIN;
vector<int> a;
void dfs(int id,int x,int r){
	if(id>n){
		if(r==m+1){
			ans=max(ans,x);
		}
		return;
	}
	dfs(id+1,x&a[id],r+1);
	dfs(id+1,x,r);
}
int main(){
	ifstream fin("and.in");
	ofstream fout("and.out");
	fin>>n>>m;
	a.resize(n+1);
	for(int i=1;i<=n;i++){
		fin>>a[i];
	}
	dfs(1,INT_MAX,1);
	fout<<ans;
	return 0;
}