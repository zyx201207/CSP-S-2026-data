#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,m,a[N];
signed main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}

