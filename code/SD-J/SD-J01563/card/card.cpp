#include<bits/stdc++.h>
using namespace std;
int a[505],ans[205],table[505];
bool vis[205];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(table,0,sizeof(table));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==1){
				memset(table,0,sizeof(table));
				memset(vis,0,sizeof(vis));
			}
			vis[a[j]]=1;
		}
		for(int j=1;j<=m;j++)if(vis[j]==1)ans[j]++; 
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
