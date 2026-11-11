#include<bits/stdc++.h>
using namespace std;
int n,a[10000000];
int p[100000];
int k,ans=-1e9;
bool f[1000000];
void dfs(int s){
	if(s==k+1){
		int gg=0;
		for(int i=1;i<=k;i++){
			if(i==1){
				gg=a[p[i]];
			}else{
				gg=gg&a[p[i]];
			}
		}
		ans=max(ans,gg);
	}else{
		for(int i=1;i<=n;i++){
			if(f[i]==0&&i>p[s-1]){
				p[s]=i;
				f[i]=1;
				dfs(s+1);
				f[i]=0;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
}