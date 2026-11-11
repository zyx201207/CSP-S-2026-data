#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int n,m;
int a[N];
bool vis[N];
int maxn=-1;
void dfs(int num,int ans,int x){
	if(ans<=maxn){
		return ;
	}
	if(x==n and num!=m+1){
		return ;
	}
	if(num==m+1 and ans>maxn){
		maxn=ans;
		return ;
	}
	if(num==1){
		ans=a[x];
	}
	for(int i=x+1;i<=n;i++){
		dfs(num+1,ans&a[x],i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	if(n<20){
		dfs(1,0,1);	
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
	}else if(m==n){
		int maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn&=a[i];
		}
	}
	cout<<maxn;
	return 0;
}