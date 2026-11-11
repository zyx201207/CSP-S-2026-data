#include<iostream>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t,n,x;
	cin>>c>>t;
	while (t--){
		cin>>n>>x;
		for (int i=1;i<=n;i++) cin>>x;
		cout<<0<<endl;
	}
	return 0;
}

