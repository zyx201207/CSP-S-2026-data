#include<iostream>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	long long a[2000005];
	while(t--){
		
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long dis=a[2]-a[1];
		for(int i=2;i<n;i++){
			if(a[i+1]-a[i]!=dis){
				cout<<0<<endl;
				continue;
			}
		}
		if(d<2*dis){
			cout<<0<<endl;
			continue;
		}
		long long r=d/dis;
		cout<<n-2*r+1<<endl;
		continue;
	}
	return 0;
}
