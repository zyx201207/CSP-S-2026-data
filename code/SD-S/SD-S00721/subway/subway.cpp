#include<cstdio>
#include<vector>
#include<iomanip>
#include<iostream>
#define int long long
using namespace std;
const int N=5e5+5,M=1e3+5,INF=1e15;
struct node{
	int id,t;
};
vector<node> vec[N];
vector<int> a[N],t[N];
int c,n,m,d,q,w[N],k[N],x,y,f[M][M];
void floyd(){
	for(int k=1;k<=n+m;k++){
		for(int l=1;l<=n+m;l++){
			for(int r=1;r<=n+m;r++){
				f[l][r]=min(f[l][r],f[l][k]+f[k][r]);
			}
		}
	}
	return;
}
void solve1(){
	for(int i=1;i<=n+m;i++){
		for(int j=1;j<=n+m;j++){
			f[i][j]=INF;
		}
	}
	for(int i=1;i<=n+m;i++){
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			vec[a[i][j]].push_back({i+m,t[i][j]});
		}
		for(int l=0;l<k[i]-1;l++){
			for(int r=l+1;r<k[i];r++){
//					cout<<a[l]<<","<<a[r]<<"\n";
				f[a[i][l]][a[i][r]]=min(t[i][l]+t[i][r],f[a[i][l]][a[i][r]]);
				f[a[i][r]][a[i][l]]=min(t[i][l]+t[i][r],f[a[i][r]][a[i][l]]);
				//同一线路里的边 
			}
		}
	}
	for(int i=1;i<=m;i++){
		int len=vec[i].size();
		for(int l=0;l<len;l++){
			for(int r=l+1;r<len;r++){
				node lx=vec[i][l],rx=vec[i][r];
//					cout<<lx.id<<","<<rx.id<<"\n"; 
				f[lx.id][rx.id]=min(f[lx.id][rx.id],lx.t+rx.t);
				f[rx.id][lx.id]=min(f[rx.id][lx.id],rx.t+lx.t);
				//同一站台里的边 
			}
		}
	}
	floyd();
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]+f[x][y]<<"\n";
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	if((n+m)*(n+m)*(n+m)<=N*M){
		solve1();
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
