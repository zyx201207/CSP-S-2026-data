#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
const int N2=1e4;
int c,n,m,d,p;
int k;
int w[N];
int a[N2][N2];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p; 
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;i++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		cout<<w[y]+a[x][y]+t[y][x];
	}
	return 0;
}

