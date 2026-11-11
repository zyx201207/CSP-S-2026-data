#include<bits/stdc++.h>
using namespace std;
int n,m;
int yxt[520000];
int a[500001];
bool vis[500001];
int l[500001];
int r[500001];
int ying[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==1){
				for(int k=j;k>=i;k--){
					if(a[k]==a[j] and k!=j){
						break;
					}
					vis[a[k]]=0;
				}
				vis[a[j]]=1;
			}else{
				vis[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(vis[j]==1){
				yxt[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<yxt[i]<<" ";
	}
	return 0;
} 
