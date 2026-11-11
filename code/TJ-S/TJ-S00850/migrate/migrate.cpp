#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		long long n,d,cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(d==2){
			cout<<n-d-1<<endl;
		}
		else if(d==3){
			cout<<n-d-2<<endl;
		}
		else{
			if(n-d+1-d<=0){
				cout<<0<<endl;
			}
			else{
				cout<<n-d+1-d<<endl;
			}
		}
	}
	return 0;
}
