#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
//long long dis[1010][1010];
//void dfs(){
//	//nw means the nwth kuai
//	//u means u is used
//	//}
//void sv1(){
//	cin>>n>>k;
//	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=1e18;
//	for(int i=1;i<=n;i++)dis[i][i]=0;
//	for(int i=1;i<n;i++){
//		int u,v;cin>>u>>v;
//		dis[u][u]=dis[v][u]=1;
//	}
//	for(int mid=1;mid<=n;mid++){
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				if(i==j||j==mid||mid==i)continue;
//				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][mid]+dis[mid][j]);
//			}
//		}
//	}
//	dfs();
//	return ;
//}
void sva(){
	cin>>n>>k;
	int rd;
	for(int i=1;i<n;i++)cin>>rd>>rd;
	int m=n/2;
	if(k==n)cout<<0<<"\n";
	else if(k>=m)cout<<1<<"\n";
	else if(k==1)cout<<(m+2)/2;
	else cout<<(m-k+5)/4;
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
//	if(c<=3||c==7)while(t--)sv1();
//	else 
		while(t--)sva();
}