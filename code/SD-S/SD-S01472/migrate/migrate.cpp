#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
long long n,d;
long long x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(x[2]-x[1]==d||x[1]-x[2]==d||x[3]-x[1]>d||x[1]-x[3]>d){
			cout<<0;
		}
		for(int i=2;i<=n;i++){
			if(x[i]-x[1]>d||x[1]-x[i]>d){
				cout<<n-i+1<<endl;
				break;
			}
		}
	}
	return 0; 
} 
