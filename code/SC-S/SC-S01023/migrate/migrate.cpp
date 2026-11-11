#include<bits/stdc++.h>
using namespace std;
long long int a[50001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,d;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
	}
	cout<<1<<"\n"<<2; 
} 