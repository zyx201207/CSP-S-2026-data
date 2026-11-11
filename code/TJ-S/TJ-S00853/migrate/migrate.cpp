//00853
#include<bits\stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int a[2000005];
	while(c--){
		memset(a,0,sizeof(a));
		int n,m;
		cin>>n>>m;
		if(m!=2||n<=2) cout<<0;
		else{
			cout<<n-2;
		}
	}
	return 0;
}

