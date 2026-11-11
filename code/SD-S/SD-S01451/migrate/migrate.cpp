#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll o,t,n,d,a[3000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>o>>t;
	while(t--){
		cin>>n>>d;
		int c=0;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
			if(i>=2){
				c=a[i]-a[i-1];
			}
		}
		int m=d/c;
		if(m==1||m>=n){
			cout<<0<<endl;
			continue;
		}else{
			m++;
			cout<<n/m<<endl;
		}
	}
	return 0;
}

