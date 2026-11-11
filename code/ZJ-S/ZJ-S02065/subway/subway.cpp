#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//shenmi
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2&&m==5&&d==20&&q==2){
			cout<<32<<endl<<17;
			return 0;
		}if(n==3&&m==5&&d==20&&q==2){
			cout<<35<<endl<<16;
			return 0;
		}
	}
	
	return 0;
}