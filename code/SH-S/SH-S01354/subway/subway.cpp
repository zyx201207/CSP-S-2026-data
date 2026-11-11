#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],b[100005],a[505][100005],t[505][100005];
int main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		for(int j=1;j<=b[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int s,e,t;
		cin>>s>>e;
		cout<<w[s]+w[e]+2;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
