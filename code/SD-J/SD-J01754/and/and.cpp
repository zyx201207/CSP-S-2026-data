#include<bits/stdc++.h>
using namespace std;
#define itn int
#define endl "\n"
#define ll long long
ll n,m,a[200005],vis[200005],maxx,yu,k,maxxx;
void dfs(int st){
	if(st==m+1){
		maxx=max(maxx,yu);
		return ;
	}for(int i=1;i<=n;i++){
		if(vis[i])continue;
		k=yu;
		st==1?yu=a[i]:yu=(yu&a[i]);
		vis[i]=1;
		dfs(st+1);
		yu=k;
		vis[i]=0;
	} 
}int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];maxxx=max(maxxx,a[i]);}
	if(n<=20){
		dfs(1);
		cout<<maxx;
		return 0;
	}else if(m==1){
		cout<<maxxx;
		return 0;
	}else if(m==2){
		maxxx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				maxxx=max(maxxx,a[i]&a[j]);
			}
		}cout<<maxxx;
		return 0;
	}else if(m==n){
		ll y=a[1];
		for(int i=2;i<=n;i++)y=y&a[i];
		cout<<y;
		return 0;
	}else if(n>2000){
		sort(a+1,a+n+1);
		cout<<a[n-2];
		return 0;
	}return 0;
}
