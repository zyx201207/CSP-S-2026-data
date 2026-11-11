#include<bits/stdc++.h> 
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 5e5+10;
const int N1 = 3e5+10;
int a[N];
int G[N];
int ans[N1]; 
int vis[N1];
int vis2[N1];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(vis[a[i]]==0){
			vis[a[i]] = i;
		}else{
			G[vis[a[i]]] = i;
			vis[a[i]] = i;
		}
	}
	
	
	for(int i = 1;i<=n;i++){
		memset(vis2,0,sizeof(vis2));
		for(int j = i;j<=n;j++){
			if(vis2[a[j]]==0){
				ans[a[j]]+=1;
				vis2[a[j]]=1;
			}			
			if(G[j]!=0){
				j = G[j]-1;
			}			
		}
	
	}
	for(int i = 1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
