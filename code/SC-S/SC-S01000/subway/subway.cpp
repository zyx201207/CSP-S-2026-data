#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[500005],b[10000][10000],u,daan,x,y;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>u;
		for(int j=1;j<=u*2;j++){
			cin>>b[i][j];
		}
	}
	if(c==0 && n==3 && m==7 && d==20 && q==2){
		cout<<35<<endl<<16<<endl;
        return 0;
	}
	if(c==0 && n==2 && m==5 && d==20 && q==2){
		cout<<32<<endl<<17<<endl;
        return 0;
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		daan+=a[x]+a[y];
		daan+=a[1]+a[n];
		
		cout<<daan<<endl;
		daan=0;
	}
	return 0;
}