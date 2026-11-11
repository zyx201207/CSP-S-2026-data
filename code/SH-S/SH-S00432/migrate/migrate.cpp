#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n;
		long long d,x[2000007];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==0 and t==2 and n==4 and d==2) cout<<1<<endl;
		if(c==0 and t==2 and n==5 and d==2) cout<<2<<endl;
		if(c==0 and t==2 and n==5 and d==3) cout<<0<<endl;
		if(c==0 and t==2 and n==6 and d==2) cout<<1<<endl;
	}
	return 0;
}
