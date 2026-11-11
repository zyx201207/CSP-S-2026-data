#include<bits/stdc++.h>
using namespace std;
const long long N=1e2+5;
int c,t,n[N],d[N],x[N][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i]>>d[i];
		for(int j=1;j<=n[i];j++){
			cin>>x[i][j];
		}
	}
	for(int i=1;i<=t;i++){
		cin>>i;
	}
	return 0;
}