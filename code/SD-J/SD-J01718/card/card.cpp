#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int cntq[300010],a[300010];
int n,m;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<cntq[i]<<" ";
	}
	return 0;
}
/*
4 3
1 2 1 3
*/


