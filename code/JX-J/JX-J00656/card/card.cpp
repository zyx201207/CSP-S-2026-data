#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000000],b[100000],c[1000000],vis[1000000];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(c,0,sizeof(c));
		int id=0;
		for(int j=1;j<i;j++) vis[j]=1;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=id;k++){
				if(c[k]==a[j]&&vis[k]==0){
					for(int x=k;x<=id;x++){
						vis[x]=1;
					}
					break;
				}
			}
			c[++id]=a[j];
		}
		for(int j=1;j<=n;j++){
			if(vis[j]==0) b[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" "; 
	return 0;
}

