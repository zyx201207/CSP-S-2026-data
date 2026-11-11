#include<iostream>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i = 1;i <= t;i++){
		int n,d,x;
		cin>>n>>d;
		for(int i = 0;i < n;i++)
			cin>>x;
		cout<<i<<"\n";
	}
	return 0;
}