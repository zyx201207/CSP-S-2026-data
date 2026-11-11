#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[5000005];
int station[100][100];
int method[100][3];
int ti[100][100];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>station[i][j];
			station[j][i]=station[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>method[i][1]>>method[i][2];
	}
	cout<<station[1][2];
	return 0;
}

