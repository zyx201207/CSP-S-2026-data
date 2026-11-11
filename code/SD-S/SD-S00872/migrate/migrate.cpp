#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,a[2000100];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if((a[2]-a[1])*2>d){
			cout<<0<<endl;
			continue;
		}
		ans=a[2]-a[1];
		int x=2;
		for(;1;x++){
			if(x*ans<=d&&(x+1)*ans>d){
				break;
			}
		}
		if(n<=x){
			cout<<0;
		}else if(n>=2*x){
			cout<<x-1;
		}else{
			cout<<n-x;
		}
	}
	return 0;
} 
