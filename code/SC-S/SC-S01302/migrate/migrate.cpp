#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,l,r;
long long k,a[N],cnt=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i1=1;i1<=t;i1++){
		cnt=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=4;i<=n;i++){
			if
			(
			a[i]-a[i-3]>k
			&&a[i]-a[i-3]<2*k
			&&a[i-1]-a[i-3]<=k
			&&a[i]-a[i-2]<=k
			)
			{
				cnt++;
			}
		}
		cout<<cnt<<" ";
	}
	return 0;
}