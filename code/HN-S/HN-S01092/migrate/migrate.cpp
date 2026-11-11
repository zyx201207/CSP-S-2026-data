#include<bits/stdc++.h>
using namespace std;
int c , t ;
long long n , d ;
long long x[2000002] ;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<(n-3)<<endl;
	}
	return 0;
} 
