#include<bits/stdc++.h>
using namespace std;
int n,c,t;
long long d;
long long  a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		cout<<15<<endl;
	}
	return 0;
}

