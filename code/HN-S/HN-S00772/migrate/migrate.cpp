#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		long long n,d,sum=0;
		for(int j=1;j<=t;j++){
			sum+=j;
		}
		cout<<sum<<endl;
	}
	return 0;
}
