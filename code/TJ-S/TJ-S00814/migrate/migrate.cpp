#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,m;
long long a[10000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<max(0ll,n-(m*2)+1)<<"\n";
	}
}
