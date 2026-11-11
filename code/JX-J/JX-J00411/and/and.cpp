#include<bits/stdc++.h>
using namespace std;
int ans=0;
int n,m;
bool vis[10000005];
int a[10000005];
void dfs(int id,int sum,int t){
	if(id==n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){	
			sum+=a[id];
			dfs(id+1,sum&a[id],t+1);
	}
}
int main (){
  freopen("and.in","r",stdin);                                            
  freopen("and.out","w",stdout);                                          
   cin>>n>>m;
   for(int i=1;i<=n;i++){
	   cin>>a[i];
   }
   dfs(0,0,1);
   cout<<ans;
return 0;
}
