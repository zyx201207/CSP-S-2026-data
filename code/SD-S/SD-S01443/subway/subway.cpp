#include <bits/stdc++.h>
using namespace std;
long long w[1001000],t1[1001000],t2[1001000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long i,c,n,m,d,q,k1,k2,xr,yr,ans = 0;
	cin>>c>>n>>m>>d>>q;
	for(i = 1;i <= m;i++){
		cin>>w[i];
	}
	cin>>k1;
	k1*=2;
	for(i = 1;i <= k1;i++){
		cin>>t1[i];
	}
	cin>>k2;
	k2*=2;
	for(i = 1;i <= k2;i++){
		cin>>t2[i];
	}
	while(q--){
		cin>>xr>>yr;
		cout<<w[xr] + w[yr];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
