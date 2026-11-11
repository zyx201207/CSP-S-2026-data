# include <bits/stdc++.h>
using namespace std;
int a[500001];
int vis[500001];
int pz[500001];
int ans[100001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int zh=0;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				vis[a[j]]=zh+1;
			}else{
				for(int k=vis[a[j]]+1;k<=zh;k++){
					vis[pz[k]]=0;
				}
				zh=vis[a[j]];
				continue;
			}
			zh++;
			pz[zh]=a[j];
		}
		for(int j=1;j<=zh;j++){
			ans[pz[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
		
	
	return 0;
}
