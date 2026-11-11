#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
bool vis[1001][1001];
int dis[1001][1001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=1e9;
			}
		}
		for(int i=1;i<=n-1;i++){
			int x,y;
			cin>>x>>y;
			vis[x][y]=1;
			vis[y][x]=1;
			dis[x][y]=1;
			dis[y][x]=1;
		}
		for(int i=1;i<=n;i++)dis[i][i]=0;
		for(int kk=1;kk<=n;kk++){
			for(int i=1;i<=kk;i++){
				for(int j=kk;j<=n;j++){
					if(vis[i][kk]==1&&vis[kk][j]==1){
						if(dis[i][kk]+1<dis[i][j]){
//							cout<<i<<' '<<kk<<' '<<j<<endl;
							dis[i][j]=dis[i][kk]+1;
						}
					}
				}
			} 
		} 
		int mx=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(dis[i][j]!=1e9)mx=max(dis[i][j],mx);
			}
		}
		if(n==k)cout<<1<<"/n";
		else cout<<mx<<"\n";		
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
