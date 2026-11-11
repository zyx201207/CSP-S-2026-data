#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,d;
	int x[2000005];
	for (int i=1;i<=t;i++){
		cin>>n>>d;
		for (int j=1;j<=n;j++){
			cin>>x[j];
		}
	}
	return 0; 
}
