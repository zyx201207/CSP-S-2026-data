#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[200010],maxn;
bool f[200010];
void dfs(int t,int s){
	if(t>m){
		maxn=max(s,maxn);
		return;
	} 
	for(int i=1;i<=n;i++)
		if(!f[i]){
			f[i]=1;
			dfs(t+1,s&a[i]);
			f[i]=0;
		}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		f[i]=1;
		dfs(1,a[i]);
		f[i]=0;
	}
	cout<<maxn;
	return 0;
}