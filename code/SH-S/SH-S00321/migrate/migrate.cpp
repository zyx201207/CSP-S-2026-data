#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	if(a[2]-a[1]<=d){
		cout<<n-3<<endl;
	}
	else
	cout<<0;
	}
	return 0;
}
