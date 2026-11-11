#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<m;++i)
		cout<<(i&1)<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}