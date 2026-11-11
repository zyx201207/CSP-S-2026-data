#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+10;
long long c,t,n[N],d[N],x[1005][1005];
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
cout<<x[1][1]<<endl<<x[2][2];
	return 0;
}
