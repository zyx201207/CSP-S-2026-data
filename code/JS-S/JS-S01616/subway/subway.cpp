#include<bits/stdc++.h>
#define ll long long
const int N=5e5+5;
using namespace std;
int c,n,m,d,q,w[N],k,a,t,x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a>>t;
	}
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
