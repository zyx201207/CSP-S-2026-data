#include<bits/stdc++.h>
using namespace std;
long long n,m,d;
long long a[200005];
void dfs(int x,int t,int c,int y){
	if(t==m){
		if(c>d){
			d=c;
		}
		return ;
	}
	if(x==n+1){
		return ;
	}
	if(y!=1){
		dfs(x+1,t+1,c&a[x],2);
	}
	dfs(x+1,t,c,2);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(i,1,a[i],1);
	} 
	cout<<d;
	return 0;
} 
