#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int c,n,m,d,q,x,y,k[505][25];
long long w[500005],t[505][500005];
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i][0];
		for(int j=1;j<=k[i][0];j++){
			cin>>k[i][j]>>t[i][j];
			
		}
	}
	if(c>=7&&c<=11){
		for(int i=1;i<=q;i++){
			cin>>x>>y;
			cout<<w[x]+w[y]<<'\n';
		}
	}
	
	return 0;
}