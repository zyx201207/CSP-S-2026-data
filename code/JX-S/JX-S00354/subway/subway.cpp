#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int M=5e5+5,N=505;

ll w[M];
int t[N][M];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a;cin>>a>>t[i][j];
		}
	}

	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		cout<<w[x]+t[x][x]+t[x][y]+w[y]<<'\n';
	}

	return 0;
}