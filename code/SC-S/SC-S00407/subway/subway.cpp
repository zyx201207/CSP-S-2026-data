#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int w[N],k[N];

int t[5050][5050],a[5050][5050];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<+m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int r=1;r<=q;r++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+t[x][y]<<'\n';
	}
	return 0;
}