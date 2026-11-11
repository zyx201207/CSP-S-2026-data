#include<bits/stdc++.h>
using namespace std;
int a[500010],b[300010],h[300010],n,m;
bool vis[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	memset(b,-1,sizeof(b));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(b[a[i]]!=-1) h[b[a[i]]]=i;
		b[a[i]]=i;
	}
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j=max(j+1,h[j])){
			if(vis[a[j]]==0){
				b[a[j]]++;
				vis[a[j]]=1;
			}
		}
	}	
	for(int i=1;i<=m;i++) printf("%d ",b[i]);
	return 0; 
}  
