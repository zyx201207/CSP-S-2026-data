#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
vector<int>a;
int dfs(int ans,int l,int s){
	if(l==m)return ans;
	int mx=0;
	for(int i=s+1;i<n;i++){
		mx=max(mx,dfs(ans&a[i],l+1,i));
	}
	return mx;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	a.resize(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<dfs((1<<20)-1,0,-1);
	return 0;
}
