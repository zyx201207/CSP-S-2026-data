#include<bits/stdc++.h>
using namespace std;
#define int long long
int t[500005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,al=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>t[i];
		al+=t[i]; 
	}
	while(q--)cout<<al;
	return 0;
}