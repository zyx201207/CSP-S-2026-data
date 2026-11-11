#include<bits/stdc++.h>
using namespace std;
int n,m,a[210000],v[210000],maxn;
void dfs(int deep,int s){
	if(deep==m+1){
		maxn=max(maxn,s);
		return;
	}
	for(int i=1;i<=n;i++){
		if(deep==1){
			s=a[i];
			v[i]=1;
			dfs(deep+1,s);
			v[i]=0;
		}
		else if(v[i]==0){
			v[i]=1;
			dfs(deep+1,s&a[i]);
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0);
	cout<<maxn;
}