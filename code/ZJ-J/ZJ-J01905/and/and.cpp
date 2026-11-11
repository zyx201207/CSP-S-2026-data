#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
bool f[200005];
void dfs(int x,int y){
	if(y==0){
		ans=max(x,ans);
		return;
	}
	for(int i=1;i<=n;i++)
		if(f[i]==0){
			f[i]=1;
			dfs(x&a[i],y-1);
			f[i]=0;
		}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		f[i]=1;
		dfs(a[i],m-1);
		f[i]=0;
	}
	cout<<ans;
}