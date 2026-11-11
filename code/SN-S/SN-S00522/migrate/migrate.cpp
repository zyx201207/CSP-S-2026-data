//张展豪  SN-S00522 西安市远东第一中学 
#include<bits/stdc++.h>
using namespace std;
long long x[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	long long c,t;
	cin>>c>>t;
	long long n,d;
	for(int i=0;i<=t;i++){
		cin>>n>>d;
		for(int j=0;i<=n;j++){
			cin>>x[i];
		}
	}
	long long g=x[2]-x[1];
	if(d%2==1){
		cout<<0<<endl;
	}
	else if(d%2==0){
		
	}
	return 0;
}
