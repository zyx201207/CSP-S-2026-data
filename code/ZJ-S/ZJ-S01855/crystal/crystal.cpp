#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
long long n;
long long m;
long long a[N];
long long p;
long long ans;
long long nw;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	p=1;
	for(long long i=2;i<=n;i++){
		nw+= (i-p)*( a[i]-a[i-1] );
		while(nw>m){
			nw-=( a[i]-a[p] );
			p++;
		}
		ans=max( ans,i-p+1 );
	}
	cout<<ans;
	return 0;
}
/*

*/
