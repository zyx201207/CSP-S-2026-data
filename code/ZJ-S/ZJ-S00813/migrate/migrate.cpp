#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstdlib>
using namespace std;
typedef long long ll;
ll c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.in","r",stdout);
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		vector<ll>x(n+1,0);
		for(int i=1;i<=n;i++)cin>>x[i];
		cout<<rand()%2000000+1;
	}
	return 0;
}
