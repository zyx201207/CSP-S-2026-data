#include<bits/stdc++.h>
using namespace std;
int x[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int p=1;p<=t;p++){
		int n,d,k=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		k=n-d*2+1;
		cout<<n-k<<endl;
	}
	return 0;
}
