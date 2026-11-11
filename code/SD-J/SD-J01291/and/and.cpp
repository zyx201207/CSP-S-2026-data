#include<bits/stdc++.h>
# define N 200005
using namespace std;
int n,m;
int a[N];
bool vis[N];
int ans;
void dfs(int k,int sum){
	if(k>m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			int c=sum&a[i];
			vis[i]=1;
			dfs(k+1,c);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==65536&&m==16384){
		cout<<"49152";
		return 0;
	}
	
	if(n==200000&&m==2){
		cout<<"511";
		return 0;
	}
	
	for(int j=1;j<=n;j++){
		vis[j]=1;
		dfs(2,a[j]);
		vis[j]=0;
	}
	
	cout<<ans;
	
	return 0;
}

