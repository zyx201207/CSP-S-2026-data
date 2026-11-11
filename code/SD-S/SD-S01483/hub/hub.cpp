#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long c,T,m,n,a[500005],b[500005],sum,ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		sum+=n+m;
	}
	cout<<(sum*8+28)%28-8
	return 0;
} 
