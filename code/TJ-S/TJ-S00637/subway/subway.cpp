#include<bits/stdc++.h>
using namespace std;
int e[1000001],s[1000001],q,c,n,m,d,p,l[100001],dp[100001][100001],v[100001][100001],w[100001][100001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=0;i<m;i++){
		cin>>l[i];
	} 
	for(int i=0;i<n;i++){
		cin>>q;
		for(int j=0;j<q;j++){
			cin>>v[i][j]>>w[i][j];
		}
	}
	for(int i=0;i<p;i++){
		cin>>s[i]>>e[i];
	}
	while(q--){
		for(int i=0;i<m;i++){
			
		}
	}
	return 0;
}
