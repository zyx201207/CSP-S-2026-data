#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout); 
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		long long x,y,k;
		cin>>x>>y;
		cout<<x<<' '<<y<<' ';
		k=y-x;
		for(long long i=2;i<n;i++){
			cin>>x;
		}
		cout<<d<<' '<<k;
		if(d<2*k){
			cout<<0<<endl;
		}
		else{
			long long i=2;
			while(k*i<=d){
				i++;
			}
			i--;
			cout<<n-i-i+1<<endl;
		}
	}
	return 0;
} 
