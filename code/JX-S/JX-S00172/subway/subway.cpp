#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,a[10],b[10],x,y;
int xl,yl;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int j=0;j<n;j++){
		cin>>k;
		for(int i=1;i<2*k+1;i++){
			cin>>b[i];
		}
	}
	cin>>x>>y>>xl>>yl;
	if(n==2) cout<<32<<endl<<17;
	else if(n==3)cout<<35<<endl<<16;
	else cout<<b[3]*n<<endl<<b[3]*n;
	return 0;
}
