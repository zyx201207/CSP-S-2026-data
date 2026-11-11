#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[10001]={};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int o=1;o<=t;o++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<o<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
