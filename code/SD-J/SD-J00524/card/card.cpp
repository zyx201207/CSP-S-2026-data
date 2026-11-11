#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1001000],f[1001000];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			f[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}
	   return 0;
}

