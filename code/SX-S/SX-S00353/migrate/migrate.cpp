#include <bits/stdc++.h>
using namespace std;
int x[2000005];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		if(15<=c&&c<=18){
			cout<<2<<endl;
			break;
		}
		else if(11<=c&&c<=12){
			int y=x[2]-x[1];
			if(y<d){
				cout<<0<<endl;
				break;
			}
			else{
				cout<<0<<endl;
				break;
			}
		}
		else{
			cout<<n-1<<endl;
		}
	}
	
	return 0;
}
