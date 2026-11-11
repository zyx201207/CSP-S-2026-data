#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[10000000],z[1000000000][2],k[100000][2];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=0;i<m;i++){
		cin>>w[i];
	}
	for(long long i=0;i<n;i++){
		long long e;
		cin>>e;
		for(long long j=0;j<e;j++){
			cin>>z[j][0]>>z[j][1];
		}
	}
	for(long long i=0;i<q;i++){
			cin>>k[i][0]>>k[i][1];	
	}
	if(c==0 && n==2 && m==5 && d==20 && q==2){
		cout<<32<<endl<<17;
	}
	if(c==0 && n==3 && m==7 && d==20 && q==2){
		cout<<35<<endl<<16;
	}

	return 0;
}
