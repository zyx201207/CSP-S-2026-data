#include<bits/stdc++.h>
using namespace std;
//#define unsigned long long unsigned long long
unsigned long long num,t;
const unsigned long long maxn=2e5+13;
unsigned long long a[maxn],sum[maxn],ans;
/*void dfs(unsigned long long x,unsigned long long y,unsigned long long z){
	if(y==2){
		
	}
}*/

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>num>>t;
	while(t--){
		unsigned long long n,m;
		cin>>n>>m;
		for(unsigned long long i=1;i<=n;i++){
			cin>>a[maxn];
		}
		for(unsigned long long i=1;i<n;i++){
			sum[i]=a[i+1]-a[i];
		}/*
		for(unsigned long long i=1;i<n;i++){
			//dfs(i,0,0);
		}*/
		if(2*m>n){
			cout<<0<<"\n";
			continue;
		}
		cout<<n/(m*2)+n%m<<"\n";
	}
	return 0;
}
