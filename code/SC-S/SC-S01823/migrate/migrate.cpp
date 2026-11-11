#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=2000005;
ll c,t,n,d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		cout<<rand()%(n*d)*rand()%(n*d)<<"\n";
	}
	return 0;
}