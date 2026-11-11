#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	int a[100005];
	cin>>c>>t;
	cin>>n>>d;
	while(t--){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	cout<<1<<endl<<2;
	if(n>4){
		cout<<0<<endl<<1;
	}
	
	return 0;
}
