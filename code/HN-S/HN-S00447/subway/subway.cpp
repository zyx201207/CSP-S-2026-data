#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500001],k[501],a[500001],t[500001],x[100001],y[100001],dp[500001][500001];
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c;
	while(c--){
		cin>>n>>m>>d>>q;
		for(int i=0;i<m;i++) cin>>w[i];
		for(int i=0;i<n;i++){
			cin>>k[i];
			for(int j=0;j<k[i];j++) cin>>a[j]>>t[j];
		}
		for(int i=0;i<q;i++) cin>>x[i]>>y[i];
		
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
