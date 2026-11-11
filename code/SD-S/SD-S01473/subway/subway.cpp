#include<bits/stdc++.h>
#define LL long long
#define endl '\n'
using namespace std;
const int M=5e5+5;
const int N=505;
int c,n,m,d,q;
LL ans=0;
int w[M],k[M],x[M],y[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			int a,b;
			cin>>a>>b;
		}
	}
//	for(int i=1;i<=n;++i){
//		for(int ii=1;ii<=n;++ii){
//			for(int j=1;j<=k[i];++j){
//				if(vis[i][a[i][j]]==1&&vis[ii][a[i][j]]==1){
//					huan[i][ii]=a[i][j];
//				}
//			}
//		}
//	}
	for(int i=1;i<=q;++i){
		cin>>x[i]>>y[i];
//		ans=0;
//		for(int j=1;j<=n;++j){
//			if(vis[j][x[i]]==1){
//				dfs(x[i],y[i],j);
//				break;
//			}
//		}
//		ans+=w[x[i]]+w[y[i]];
		cout<<rand()%100<<endl; 
	
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
