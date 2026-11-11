#include<bits/stdc++.h>
using namespace std;
	int m,n,c,d,q,w[500005],k[500005],t[10005][10005],cnt,x,y,mx;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			cin>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cnt=w[x]+w[y]+t[x][x]+t[x][y];
		cout<<cnt<<endl;
		cnt=0;
	}
	return 0;
} 
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

