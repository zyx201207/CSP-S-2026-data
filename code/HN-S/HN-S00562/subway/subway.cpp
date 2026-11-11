#include<bits/stdc++.h>
#define ll long long
using namespace std;
int k3[250000],k[250000],c,n,m,d,q,o,u,p,yy,yp,zz,t;
ll b;
struct node{
	int les,link;
}a[508][508];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>k[i];
	}
	for(int i=1;i<=n;i++){
		cin>>o;
		t=0;
		for(int j=1;j<=o;j++){
			cin>>yy>>zz;
			k3[yy]=zz;
		}
	}
	while(q--){
		cin>>u>>p;
		cout<<k[u]+k[p]+k3[u]+k3[p]<<"\n";
	}
	return 0;
} 
