#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,n;
	cin>>c>>n;
	while(n--){
		int a[100000];
		int o,p;
		cin>>o>>p;
		for(int i=1;i<=o;i++){
			cin>>a[i];
		}
		cout<<o-p-1<<endl;
	}
	return 0;
}

