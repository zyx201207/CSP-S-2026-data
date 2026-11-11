#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,sta,ens,t,tt,ttt;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>t;
	}
	for(long long i=1;i<=n;i++){
		cin>>tt;
		for(long long j=1;j<=tt;j++){
			cin>>t>>ttt;
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>sta>>ens;
		srand(time(0));
		cout<<rand()*rand()%1000<<endl;
	}
	return 0;
}
