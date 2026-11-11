#include <iostream>
#include <cstdio>

#define int long long

using namespace std;

int c,T,n,d;
const int N=2e6+10;
int a[N];
int x,pyl;

signed main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		pyl=d+1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<n-pyl<<"\n";
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
