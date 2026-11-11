#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,q;
	cin>>c>>q;
	long long f[5]={};
	while(q--){
		memset(f,0,sizeof(f));
		int n;
		long long d,p;
		cin>>n>>d;
		for(int i=0;i<3;i++)cin>>f[i];
		for(int i=3;i<n;i++)cin>>p;
		if(n>=4&&f[2]-f[0]<=d)cout<<n-3<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
