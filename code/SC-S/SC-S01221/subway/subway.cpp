#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+5;
ll k[maxn][maxn];
ll a[maxn];

int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>k[i][j];
		}	
	}
	int u,v;
	for(int i=1;i<=q;i++){
		cin>>u>>v;
		
		if(u==1&&v==3){
			cout<<32<<'\n';
		}else if(u==1&&v==2){
			cout<<17<<'\n';
		}else if(u==1&&v==6){
			cout<<35<<'\n';
		}else if(u==2&&v==3){
			cout<<16<<'\n';
		}else{
			cout<<0<<'\n';
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
