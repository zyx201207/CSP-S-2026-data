#include<bits/stdc++.h>
using namespace std;
long long n,c,m,a[20005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c=max(c,a[i]);
	}
	cout<<c;
	return 0;
} 
