#include<bits/stdc++.h>
using namespace std;
int n,m,a[300002],ans[300002];
bool vis[300002];
int main()
{
 freopen("card.in","r",stdin);
 freopen("card.out","w",stdout);
 cin>>n>>m;
 for(int i=1;i<=n;i++) cin>>a[i];
 for(int i=1;i<=n;i++){
 	memset(vis,0,sizeof(vis));
 	stack<int> t;
 	for(int j=i;j<=n;j++)
 	{
 		if(vis[a[j]]){
 			int u;
 			while(u!=a[j]){
 				u=t.top();
 				vis[u]=false;
 				t.pop();
			 }
		 }
 		t.push(a[j]);
 		vis[a[j]]=true;
	}
	for(int j=1;j<=m;j++) ans[j]+=vis[j];
 }
 for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
 return 0;
}

