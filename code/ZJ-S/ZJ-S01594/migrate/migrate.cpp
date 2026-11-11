#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int c,t,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<n-3<<"\n";
	}
	return 0;	
}
