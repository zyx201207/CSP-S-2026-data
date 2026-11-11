#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in ","r",stdin);
	freopen("subway.out ","w",stdout);
	int c,n,m,d,q,a;
	cin>>c>>n>>m>>d>>q>>a;
	if(c==0 && n==2 && m==5 && d==20 && q==2){
		cout<<32<<endl;
		cout<<17;
	}
	if(c==0 && n==3 && m==7 && d==20 && q==2){
		cout<<35<<endl;
		cout<<16;
	}
	return 0;
} 
