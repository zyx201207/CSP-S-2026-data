#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[20005],k[505],t1[505][505],t2[505][20005];
void bfs(int lin,int lin2){
	if(t1[lin][lin2]!=1e10||lin==lin2)return;
	for(int i=1;i<=m;i++){
		if(t2[lin][i]!=0&&t2[lin2][i]!=0){
			t1[lin][lin2]=min(t1[lin][lin2],t2[lin][i]+t2[lin2][i]);
			t1[lin2][lin]=t1[lin][lin2];
		}
	}
	for(int i=1;i<=n,i!=lin,i!=lin2;i++){
		bfs(lin,i);
		bfs(i,lin2);
		t1[lin][lin2]=min(t1[lin][lin2],t1[lin][i]+t1[i][lin2]);
		t1[lin2][lin]=t1[lin][lin2];
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n,i!=j;j++){
			t1[i][j]=1e10;
		}
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin >> a >> t;
			t2[i][a]=t;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n,i!=j;j++){
			if(t1[i][j]==1e10){
				bfs(i,j);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y,minan=1e10;
		cin >> x >> y;
		for(int p=1;p<=n;p++){
			for(int q=1;q<=n;q++){
				if(t2[p][x]>0&&t2[q][y]>0){
					minan=min(minan,t2[p][x]+t1[p][q]+t2[q][y]);
				}
			}
		}
		minan+=w[x]+w[y];
		cout << minan << endl;
	}
	return 0;
}/*0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2 
4 3 2 5 100 4 6 6 7
1 6 
2 3*/
