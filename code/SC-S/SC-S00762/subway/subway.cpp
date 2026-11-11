#include <iostream>
using namespace std;
const int M=5e5+5,N=505;
int c,m,n,d,q,w[M],x[N][2*M],maxn;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin >> w[i];maxn+=w[i];
	}for (int i=1;i<=n;i++){
		cin >> x[i][0];
		for (int j=1;j<=2*x[i][0];j++){
			cin >> x[i][j];
			if (!(j%2)) maxn += x[i][j];
		}
	}int l,r;
	while (q--){
		cin >> l>> r;
		int ran;
		cout << (ran%maxn)<<'\n'; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}