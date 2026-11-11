#include<bits/stdc++.h>
using namespace std;
int n,m,z[500005];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>z[i];
	}
	cout<<z[n];
	return 0;
} 
