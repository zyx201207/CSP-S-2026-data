#include<bits/stdc++.h>
using namespace std;
int n,a[202005],m,vis[200005],b[200005],l=1e9,r,las[544512],t[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n<500&&m<200){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				b[j]=a[j];
			}
			for(int j=i;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(b[k]==b[j]){
						for(int l=j+1;l<=k;l++){
							b[l]=0;
						}
					}
				}
			}
			for(int k=i;k<=n;k++){
				vis[b[k]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<vis[i]<<" ";
		}
	}else{
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if((las[a[j]]>l&&las[a[j]]<r)||las[a[j]]==0){
					las[a[j]]=j;
				}else{
					if(las[a[j]]<=l){
						l=las[a[j]];
						r=j+1;
					}
				}
			}
			if(l!=1e9){
				for(int j=i;j<=l;j++){
					t[a[j]]++;
				}
				for(int j=r;j<=n;j++){
					t[a[j]]++;
				}
			}else{
				for(int j=i;j<=n;j++){
					t[a[j]]++;
				}
			}
			l=1e9;
			r=0;
			memset(las,0,sizeof(las));
			memset(vis,0,sizeof(vis));
		}
		for(int i=1;i<=m;i++){
			cout<<t[i]<<" ";
		}
	}
	return 0;
} 
