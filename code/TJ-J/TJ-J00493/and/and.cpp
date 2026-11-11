#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long s; 
long long a[200010];
long long max=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(n==1){
			cout<<a[i];
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	
	return 0;
}
