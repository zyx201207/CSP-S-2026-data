#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
long long maxx;
void dfs(int t,int k,long long ans){
	if(k==m){
		maxx=max(maxx,ans);
		return ;
	}
	if(t>n){
		return ;
	}
	dfs(t+1,k+1,ans&a[t]);
	dfs(t+1,k,ans);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		for(int i=1;i<=n-m;i++){
			dfs(i+1,1,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	for(int i=1;i<=n;i++){
		maxx=max(maxx,a[i]);
	}
	cout<<maxx;
	return 0;
}

