#include<bits/stdc++.h>
using namespace std;
long long n,m;
int ans[100010],zhu[200010],a[200010],vis[100010],Top,Now;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++){
		Top=0,Now=0;
		for(int j=1;j<=m;j++)vis[j]=0;
		while(Now+i<=n){
			if(vis[a[i+Now]]){
				Top=vis[a[i+Now]];
				for(int j=1;j<=m;j++){
					if(vis[j]>Top)vis[j]=0;
				}
			}else{
				Top++;
				vis[a[i+Now]]=Top;
			} 
			zhu[Top]=a[i+Now];
			Now++;
		}
		for(int j=1;j<=Top;j++){
			ans[zhu[j]]++;
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;	
}
