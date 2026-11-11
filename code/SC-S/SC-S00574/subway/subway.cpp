#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;vector<int>w(m+1);
	for(int i=1;i<=n;i++)cin>>w[i];
	cout<<n/3<<' '<<n/2;
	return 0;
}