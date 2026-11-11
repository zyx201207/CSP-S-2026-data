#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d,x[2000001];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			int p;
			cin>>p;
			x[p]=1;
		}
		cout<<n;
	}
	return 0;
}
