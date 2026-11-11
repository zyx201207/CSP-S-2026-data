#include<bits/stdc++.h>
using namespace std;
int a[200010],cnt;


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	for(int i=1; i<=t; i++){
		cin>>n>>d;
		for(int j=1; j<=n; j++){
			cin>>a[j];
		}
		for(int k=4; k<=n; k++){
			cnt+=i;
		}
		cout<<cnt<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
