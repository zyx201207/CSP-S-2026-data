#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k;
long long w[500005],a[500005],t[500005];
long long edge[5005][5005];
long long vis[5005][5005],mx,my;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		vis[i][i]=1;
		for(int j=i+1;j<=m;j++){
			edge[i][j]=edge[j][i]=0;
			vis[i][j]=vis[j][i]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int x=j+1;x<=k;x++){
				vis[a[j]][a[x]]=vis[a[x]][a[j]]=1;
				if(edge[a[j]][a[x]]==0){
					edge[a[j]][a[x]]=edge[a[x]][a[j]]=t[j]+t[x];
				}else{
					if(t[j]+t[x]<=edge[a[j]][a[x]]){
						edge[a[j]][a[x]]=edge[a[x]][a[j]]=t[j]+t[x];
					}
				}
			}
		}
	} 

	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			if(vis[i][j]==1&&i!=j){
				for(int x=j+1;x<=m;x++){
					if(vis[j][x]==1&&j!=x&&i!=x){
						vis[i][x]=vis[x][i]=1;
						if(edge[i][x]==0){
							edge[i][x]=edge[x][i]=edge[i][j]+edge[j][x];
						}else{
							if(edge[i][j]+edge[j][x]<=edge[i][x]){
								edge[i][x]=edge[x][i]=edge[i][j]+edge[j][x];
							}
						}
					}
				}
			}
		}
	}

	for(int i=1;i<=q;i++){
		cin>>mx>>my;
		cout<<edge[mx][my]+w[mx]+w[my]<<"\n";
	}
	return 0;
}