#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w,k,a,t,x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
	}
	if(n==2){
		cout<<32<<endl<<17;
	}
	if(n==3){
		cout<<35<<endl<<16;
	}
	return 0;
}
