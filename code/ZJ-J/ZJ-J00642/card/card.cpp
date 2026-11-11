#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[500005],st[500005],str[500005],ve[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=1; i<=n; i++){
		int vis[500005],k=0; 
		memset(vis,0,sizeof(vis));
		memset(ve,0,sizeof(ve));
		for(int j=i; j<=n; j++){
			if(vis[a[j]]==1){
				for(int h=1;h<=k;h++){
					if(ve[h]==a[j]){
						k=h;
						break;
					}
				}
			}
			else{
				vis[a[j]]=1;
				ve[++k]=a[j];
			}
		}
		for(int j=1; j<=k; j++) st[ve[j]]++;
	}
	for(int i=1 ;i<=m; i++) cout<<st[i]<<" ";
	return 0;
} 
