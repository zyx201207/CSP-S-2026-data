#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){ 
	freopen("migrate.in", "r",stdin);
	freopen("migrate.out", "w",stdout);
	int c,q;
	cin>>c>>q;
	for(int i=0;i<q;i++){
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
	}
	return 0;
}
