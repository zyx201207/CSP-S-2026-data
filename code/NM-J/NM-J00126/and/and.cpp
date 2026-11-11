#include<bits/stdc++.h>
using namespace std;
/*
5 3 
31 3 1 15 7
7

4 2 
3 15 12 12
12
*/
int a[200086];
int n,m;
int vis[200086];
int ans=-10086;
void dfs(int hm,int f){
//	for(int i=1;i<=n;i++)cout<<vis[i];
//	cout<<endl;
	if(hm<=0){
//		cout<<"-----------------------------"<<endl;
		ans=max(ans,f);
		return;
	}
	for(int i=1;i<=n;i++){
		int nx=f&a[i];
//		cout<<f<<"&"<<a[i]<<"="<<nx<<endl;
		if(nx<ans){
//			cout<<"mix"<<endl;
			continue;
		}
		if(vis[i]==1){
//			cout<<"vis"<<endl;
			continue;
		}
		vis[i]=1;
		
		dfs(hm-1,nx);
		vis[i]=0;
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(m-1,a[i]);
		vis[i]=0;
	}
//	cout<<endl<<"____________________"<<endl;
	cout<<ans;
	return 0; 
} 
