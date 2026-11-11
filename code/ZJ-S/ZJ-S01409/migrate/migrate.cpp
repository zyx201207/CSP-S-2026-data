#include<bits/stdc++.h>
using namespace std;
int c,t;
const int N=1e5+10;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d;
		long long a[N];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(a[2]-a[1]>=0){
			if(a[2]-a[1]<=d && a[3]-a[1]>d){
				cout<<n-2<<'\n';
			}
		}
	}
	return 0;
}