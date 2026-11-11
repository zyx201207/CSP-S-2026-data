#include<bits/stdc++.h>
#define ll long long
#define CLOSE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
int c,n,m,d,q;
int a[500005];
int flag[2001];//jiedian
int ttk[501][2001];
int station[2001][3];
int lineswap[501];
int huancheng[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	CLOSE
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}//c 1~11
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int who;
			cin>>who;
			cin>>ttk[i][who];
			if(station[who][1]){
				station[who][1]=i;
			}
			else{
				station[who][2]=i;
			}
			flag[who]++;
		}
	}
	for(int i=1;i<=m;i++){
		if(flag[i]>=2){
			int aas[21]={0},aascnt=0;
			for(int v:station[i]){
				aas[++aascnt]=v;
			}
			for(int ii=1;ii<=aascnt-1;ii++){
				for(int jj=ii+1;jj<=aascnt;jj++){
					lineswap[ii]=jj;
					lineswap[jj]=ii;
					huancheng[ii][jj]=i;
				}
			}
		}
	}
	/*int x,y;
	cin>>x>>y;
	cout<<huancheng[x][y];*/
	while(q--){//xunwen
		int x,y;
		cin>>x>>y;
		if(lineswap[station[x][1]]!=station[y][1]){
			cout<<a[x]+ttk[station[x][1]][x]+a[y]+ttk[station[y][1]][y]+ttk[station[x][1]][huancheng[x][y]]+ttk[station[y][1]][huancheng[x][y]]<<endl;
		}
		else{
			cout<<a[x]+ttk[station[x][1]][x]+a[y]+ttk[station[y][1]][y]<<endl;
		}
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

