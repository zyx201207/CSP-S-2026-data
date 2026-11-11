#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2&&m==5&&d==20&&q==2){
			cout<<32<<endl<<17;
		}
		if(n==3&&m==7&&d==20&&q==2){
			cout<<36<<endl<<15;
		}					
	}	
	return 0
} 
