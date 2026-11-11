#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[500005];
bool vis[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j+=1){
			//cout<<j;
			if(vis[a[j]]){
				int k=j-1;
				for(;a[j]!=a[k];k--){
					vis[a[k]]=false;
				}
			}vis[a[j]]=true;
			for(int i=1;i<=m;i++){
				//cout<<(vis[i])<<' ';
			}//cout<<'\n';
		}for(int i=1;i<=m;i++){
			if(vis[i]){
				c[i]++;
			}
		}
	}for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
