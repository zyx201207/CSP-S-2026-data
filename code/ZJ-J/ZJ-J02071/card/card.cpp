#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,m,a[N],b[N],t[N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		cout<<i<<' ';
	}
	return 0;
}
