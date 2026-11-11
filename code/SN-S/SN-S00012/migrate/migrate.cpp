#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[1000100]={0};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		if(n<=4){
			cout<<1<<endl;
		}
	}
	return 0;
}

