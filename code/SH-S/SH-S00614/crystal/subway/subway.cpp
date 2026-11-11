#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N=1e3+10,M=5e2+10,K=5e5+10; 
int w[N],a[M][N],t[M][N],k[M],dis[N],g[N][N],ww[K];
struct st{
	int aa,tt;
};
st g1[K],g2[K];
cmp(st a,st b){
	return a.aa<b.aa;
}
int _,n,m,d,q;
void bfs(int x){
	deque<int> dq;
	for(int i=1;i<=m;i++){
		dis[i]=1e18+10;
	} 
	dis[x]=0;
	dq.push_back(x);
	while(!dq.empty()){
		int y=dq.front();
		dq.pop_front();
		for(int i=1;i<=m;i++){
			if(g[y][i]>=0){
				if(dis[i]>dis[y]+g[y][i]){
					dis[i]=dis[y]+g[y][i];
					dq.push_back(i);
					//cout<<y<<' '<<i<<' '<<dis[i]<<endl;
				}
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g,-1,sizeof g);
	cin>>_>>n>>m>>d>>q;
	if(n==2){
		for(int i=1;i<=m;i++){
			cin>>ww[i];
		}
		int n1,n2;cin>>n1;
		for(int j=1;j<=n1;j++){
			cin>>g1[j].aa>>g1[j].tt;
		}
		cin>>n2;
		for(int j=1;j<=n2;j++){
			cin>>g2[j].aa>>g2[j].tt;
		}
		sort(g1+1,g1+n1+1,cmp);
		sort(g2+1,g2+n2+1,cmp);
		
		int ans=1e18+10;
		
//		for(int j=1;j<=n1;j++){
//			cout<<g1[j].aa<<' '<<g1[j].tt<<endl;
//		}
//		cout<<endl;
//		for(int j=1;j<=n2;j++){
//			cout<<g2[j].aa<<' '<<g2[j].tt<<endl;
//		}
		int i=1,j=1;
		while(i<=n1&&j<=n2){
			i++;
			if(g1[i].aa>g2[j].aa){
				j++;
				i--;
			}
			
			else if(g1[i].aa==g2[j].aa){
				ans=min(ans,g1[i].tt+g2[j].tt);
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;cin>>x>>y;
			int anss=ww[x]+ww[y];
			int xxx=0,yyy=0;
			for(int j=1;j<=n1;j++){
				if(x==g1[j].aa){
					anss+=g1[j].tt;
					xxx+=1;
				}
				if(y==g1[j].aa){
					anss+=g1[j].tt;
					yyy+=1;
				}
			}
			if(xxx==yyy){
				cout<<anss;
				return 0;
			}
			for(int j=1;j<=n2;j++){
				if(x==g2[j].aa){
					if(xxx!=1){
						anss+=g2[j].tt;
					}
					
					xxx+=2;
				}
				if(y==g2[j].aa){
					if(yyy!=1){
						anss+=g2[j].tt;
					}
					
					yyy+=2;
				}
			}
			if(xxx!=yyy&&xxx<3&&yyy<3){
				anss+=ans;
			}
			cout<<anss<<endl;
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<k[i];j++){
			for(int jj=j+1;jj<=k[i];jj++){
				g[a[i][j]][a[i][jj]]=t[i][j]+t[i][jj];
				g[a[i][jj]][a[i][j]]=t[i][j]+t[i][jj];
				//cout<<a[i][jj]<<' '<<a[i][j]<<' '<<g[a[i][j]][a[i][jj]]<<endl;
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		bfs(x);
		cout<<dis[y]+w[x]+w[y]<<endl;
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


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
