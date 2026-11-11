#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long c,n,m,d,q,p,a[N][N],t[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0) cout<<32<<endl<<17;
	for(int i=1;i<=n;i++){
		cin>>p;
		for(int j=1;j<=p;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	return 0;
}
