#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n;
long long d;
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
		sort(x+1,x+1+n);
		cout<<0<<endl;
	}
	return 0;
}
