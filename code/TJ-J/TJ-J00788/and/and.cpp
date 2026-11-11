#include <bits/stdc++.h>
using namespace std;

long long n,m,a[1000002],k;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
for(int i=1;i<=n;i++){
	for(int j=m;j<i;j++){
		k=max(a[i]&a[j],k);
	}
}cout<<k;

	return 0;
}
