#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,mm;
int a[200005];
int ans[200005];
int g[200005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>mm;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=n;i>n-mm;i--){
		cout<<a[i]<<' ';
	}
	return 0;
}
/*
4 3 
1 2 1 3

*/
