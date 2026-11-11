#include<bits/stdc++.h>
using namespace std;
const int N=2E5+10;
#define ll long long
int t,c,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
		cout<<ceil(1.0*n/d)-1<<"\n";
	return 0;
}
