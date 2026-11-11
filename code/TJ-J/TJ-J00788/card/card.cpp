#include <bits/stdc++.h>
using namespace std;
long long a[1000008],c[1000003];long long b,n;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>b;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
for(int i=1;i<=n;i++){
	cout<<a[i]<<' ';
	
}
	return 0;
}
