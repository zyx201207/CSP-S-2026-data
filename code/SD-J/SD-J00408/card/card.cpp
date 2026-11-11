#include<bits/stdc++.h>
using namespace std;
int tp[200005],card[200005],vis[200005],n,m,q[200005],k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>card[i];
	for(int i=1;i<=n;i++){
		memset(q,0,sizeof(q));
		memset(vis,0,sizeof(vis));
		k=0;
		for(int j=i;j<=n;j++){
			q[++k]=card[j];
			if(vis[card[j]]==1){
				int p;
				for(int l=1;l<=n;l++){
					if(q[l]==card[j]){
						p=l;
						break;
					}
				}
				for(int l=p;l<=n;l++){
					if(q[l]==card[j]&&l!=p)break;
					vis[q[l]]=0;
					q[l]=-1;
				}
				vis[card[j]]=1;
			}
			else vis[card[j]]=1;
		}
		for(int l=1;l<=n;l++){
			if(vis[l]==1)tp[l]++;
		}
	} 
	for(int i=1;i<=m;i++)cout<<tp[i]<<' ';
}
