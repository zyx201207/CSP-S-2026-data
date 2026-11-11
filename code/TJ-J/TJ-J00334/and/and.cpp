#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],maxx,b;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b=0;
		for(int j=i;j<=m;j++){
			b=a[j]&&b;
		}
		maxx=max(maxx,b);
	}
	cout<<maxx;
	return 0;
} 
