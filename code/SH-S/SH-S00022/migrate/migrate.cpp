#include <bits/stdc++.h>
using namespace std;

int c,t;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int x[205];
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<n*(n-1)/2<<endl;
	}
	
	return 0;
}
