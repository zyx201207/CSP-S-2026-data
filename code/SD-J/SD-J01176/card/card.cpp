#include<bits/stdc++.h>
using namespace std;
int vis[200005];
int cnt[200005];
int a[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]%2==0&&vis[a[j]]!=0){
				memset(vis,0,sizeof(vis));
				vis[a[j]]=1;
			}
			else {
				vis[a[j]]+=1;
			} 
		}
		for(int k=1;k<=m;k++){
			cnt[k]+=vis[k];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
