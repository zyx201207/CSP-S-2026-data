#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q;
ll w[20005],road[20005][505],shift[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(road,-1,sizeof(road));
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i!=j)  shift[i][j]=LLONG_MAX;
		}
	
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int j=1;j<=k;j++){
			int a,t; cin>>a>>t;
			road[a][i]=t;
			for(int l=1;l<=n;l++){
				if(road[a][l]==-1 || l==i) continue;
				shift[l][i]=min(shift[l][i],road[a][l]+road[a][i]);
				shift[i][l]=shift[l][i];
			}
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(shift[i][k]==LLONG_MAX || shift[k][j]==LLONG_MAX) continue;
				shift[i][j]=min(shift[i][j],shift[i][k]+shift[k][j]);
				shift[j][i]=shift[i][j];
			}
		}
	}

	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		 	cout<<shift[i][j]<<" ";
		cout<<endl;
	}*/
		

	while(q--){
		int x,y; cin>>x>>y; ll ans=LLONG_MAX;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(road[x][i]!=-1 && road[y][j]!=-1){
					ans=min(ans,road[x][i]+road[y][j]+shift[i][j]);
				}
			}	
		}
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
} 
