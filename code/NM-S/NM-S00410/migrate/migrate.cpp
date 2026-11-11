#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,e=0,su=0;
int a[100006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<n-1-d<<endl;
	}
	
}
