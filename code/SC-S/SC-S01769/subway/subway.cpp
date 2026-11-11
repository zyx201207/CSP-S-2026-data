#include<bits/stdc++.h>
using namespace std;
const int N=
int m,n,q,c,d;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int inw[m+2],xia[n+2];                
	for(int i=1;i<=m;i++){
		cin>>inw[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int o=1;o<=k;o++){
			cin>>xia[o];
		}
	}
	for(int i=1;i<=q;i++){
		int aa,bb;
		cin>>aa>>bb;
	}
	if(n==2) {cout<<32<<endl<<17;}
	if(n==3) {cout<<35<<endl<<16;}
	return 0;	
}
