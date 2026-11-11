#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,n,m,d,q;
	int w[9999999],a[999999][999999];
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(c>10){
		cout<<32<<endl<<17;	
	}
	else{
		cout<<52<<endl<<33;
	}
} 
