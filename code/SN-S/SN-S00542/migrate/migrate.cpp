#include<iostream>
using namespace std;
#define ll long long
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,m,c,t;
	cin>>c>>t;
	while (t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			int p;
			cin>>p;
		}
		cout<<n/m<<endl;
	}
	
	return 0;
}

