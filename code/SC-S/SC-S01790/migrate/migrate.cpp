#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long a[N];


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,sl;long long d;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i]; 
		}
		if(a[n-1]-a[n-2]>d/2){
			cout<<0;
		}else{
			cout<<n;
		}
		cout<<"\n";
	}
}