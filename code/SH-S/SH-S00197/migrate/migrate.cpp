#include<bits/stdc++.h>
using namespace std;

int c,t,n,d;
int a[2000005];

int main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		if((a[2]-a[1])!=d-1){
			cout<<0<<endl;
		}
		else{
			cout<<n-3<<endl;
		}
	}
	return 0;
}
