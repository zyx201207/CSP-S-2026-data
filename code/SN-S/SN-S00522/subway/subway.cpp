//张展豪  SN-S00522 西安市远东第一中学 
#include<bits/stdc++.h>
using namespace std;
long long t[1000005];
long long w[1000005];
long long y[1000005];
long long x[1000005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,r;
	cin>>c>>n>>m>>d>>q;
	int k;
	for(int i=0;i<=m;i++){
		cin>>w[i];
		cin>>k; 
		for(int j=2;j<=2*k+1;j++){
			cin>>t[j];
		}	 
	}
	cin>>r;
	for(int l=r+n+2;l<=m;l++){
		cin>>x[l]>>y[l];
	} 
	return 0;
}
