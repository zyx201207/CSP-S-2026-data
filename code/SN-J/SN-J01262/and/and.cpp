#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,mx=-1e9;
int a[200005];
bool f[200005];
void dfs(int k,int x){
	if(x==m){
		vector<int> v;
		for(int i=1;i<=n;i++) if(f[i]) v.push_back(a[i]);
		int s=v[0];
		for(int i=1;i<v.size();i++){
			s=(s&v[i]);
		}
		if(v.size()==m) mx=max(mx,s);
		return ;
	}
	if(k==n+1) return ;
	f[k]=0;
	dfs(k+1,x);
	f[k]=1;
	dfs(k+1,x+1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0);
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
