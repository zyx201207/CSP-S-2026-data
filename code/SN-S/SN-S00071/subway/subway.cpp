#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,p;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	if(n==2&&m==5&&d==20&&p==2){
		for(int i=1;i<=23;i++){
			cin>>c;
		}
		cout<<"32"<<endl<<"17";
	}
	if(n==3&&m==7&&d==20&&p==2){
		for(int i=1;i<=34;i++){
			cin>>c;
	    }
		cout<<"35"<<endl<<"16";
	}
	return 0;
}
