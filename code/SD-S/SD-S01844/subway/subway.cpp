#include <bits/stdc++.h>
using namespace std;
int W[1000],A[100][100],T[100][100];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int i,j,o,n,m,c,d,q,k,x,y;
	cin>>c>>n>>m>>d>>q;
	for(i = 1 ; i <= m ; i++){
		cin>>W[i];
	}
	for(i = 1 ; i <= n ; i++){
		cin>>k;
		for(j = 1 ; j <= k ; j++){
			cin>>A[i][j]>>T[i][j];
		}
	}
	for(i = 1 ; i <= q ; i++){
		cin>>x>>y;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
