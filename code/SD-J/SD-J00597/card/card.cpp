#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m; 
int a[1000010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]; 
	}
	return 0;
} 
