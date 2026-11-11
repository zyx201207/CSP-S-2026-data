#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int a[1000010];
int n,m;
int maxx=-1e18;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=m){
		int n=a[i-m+1];
		for(int j=1;j<m;j++){
			n&=a[i-j+1];
		}
		maxx=max(n,maxx);
		}
	}
	cout<<maxx;
	return 0;
}


