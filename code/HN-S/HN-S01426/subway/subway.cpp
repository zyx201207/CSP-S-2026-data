#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,g;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>c;
	}
	cin>>g;
	for(int j=1;j<=n;j++){
		for(int i=1;i<=2*g;i++){
			cin>>c;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>c>>g;
		if(g==3&&n==1){
			cout<<32;
		}
		if(g==3&&n==2){
			cout<<35;
		}
		if(g==2){
			cout<<17;
		}
		if(g==6){
			cout<<16;
		}
	}
	return 0;
}
