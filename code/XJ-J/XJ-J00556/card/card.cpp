#include <bits/stdc++.h>
using namespace std;

long long n,m,a[500005],ans[300005],xm[500005];

int main(){
	freopen("card.in","r",stdin);
	freopen("catd.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>xm[i];
	} 
	for(long long i=1;i<=n;i++){
		for(long long j=n-i;j<=n;i++){
				cout<<xm[i]*j;
		}
	}
	return 0;
}