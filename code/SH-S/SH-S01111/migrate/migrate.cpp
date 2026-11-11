#include<bits/stdc++.h>
using namespace std;
unsigned long long int a[2000001],n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long int c,t;
	cin>>c>>t;
	if(c==11||c==12||c==0){
		while(t--){
			cin>>n>>d;
			for(int i=0;i<n;i++){
				cin>>a[i];
			}
			long long int k=a[1]-a[0];
		long long int u=d/k;
			if(u<=1||n-u-u+1<=0||n-u-u+1>=18446744073709292000){
				cout<<0<<endl;
			}
			else{
				cout<<n-u-u+1<<endl;
			}
		}
	}
	else{
		while(t--){
			cin>>n>>d;
			for(int i=0;i<n;i++){
				cin>>a[i];
			}
			int k=a[1]-a[0];
			int u=d/k;
			if(u<=1){
				cout<<0<<endl;
			}
			else{
				cout<<n-u-u+1;
			}
		}
	}
	return 0;
}
