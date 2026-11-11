#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-100000;
vector<int> path;
vector<int> a;
void dfs(int start){
	if(path.size()==m){
		int sum=path[0];
		for(int x=1;x<m;x++){
			sum&=path[x];
		}
		ans=max(ans,sum);
		return;
	}
	for(int i=start;i<n;i++){
		path.push_back(a[i]);
		start++;
		dfs(start);
		path.pop_back();
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	a.resize(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0);
	cout<<ans;
	return 0;
}
