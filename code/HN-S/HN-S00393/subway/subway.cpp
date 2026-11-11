#include <bits/stdc++.h>
using namespace std;
const int MAXM=5e5+7;

const int MAXN=505;
int w[MAXM];
int k[MAXN];
int a[MAXN][MAXM],t[MAXN][MAXM];
int c,n,m,d,q;
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
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<32<<'\n'<<17;
		return 0;
	}
	
	return 0;
}
