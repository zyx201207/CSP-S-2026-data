#include<bits/stdc++.h>
using namespace std;
long long fside,fd;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t>0){
		t--;
		long long n,d;
		cin>>n>>d;
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n>=d+1){
			cout<<n-d-1<<endl;
		}
		else{
			cout<<0<<endl;
		}		
	}
	return 0;
}
