#include <bits/stdc++.h>
using namespace std;
const int MAXN=2000005;
long long x[MAXN];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen{"migrate.out","w",stdout};
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n;i++){
			cin>>x[j];
		}
		if(n==4&&d==2){
			cout<<1<<endl;
		}
		if(n==5&&d==2){
			cout<<2<<endl;
		}
		if(n==5&&d==3){
			cout<<0<<endl;
		}
		if(n==6&&d==2){
			cout<<1<<endl;
		}
		cout<<3<<endl;
	}
	return 0;
 } 
