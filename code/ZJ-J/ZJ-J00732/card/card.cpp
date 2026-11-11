#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],answer,vis[100005],b[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n<=500){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				b[j]=a[j];
				for(int k=i;k<=j-1;k++){
					if(b[k]==a[j]){
						for(int x=k;x<=j-1;x++){
							b[x]=0;
						}
					}
				}
			}
			for(int j=i;j<=n;j++){
				vis[b[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<vis[i]<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		vis[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		printf("%d ",vis[i]);
	}
	return 0;	
}
