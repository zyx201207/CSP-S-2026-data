#include<bits/stdc++.h>
using namespace std;
int const MAXN=2e5+5; 
int n,m,a[MAXN],ans=0;
bool f[MAXN];
void dfs(int s,int k){
	if(k==0){
		ans=max(ans,s);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			dfs(s&a[i],k-1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f[i]=1;
		dfs(a[i],m-1);
		f[i]=0;
	}
	cout<<ans;
	return 0;
}
