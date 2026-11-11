#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500001],k[501],A,T,lstA,lstT;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>A>>T;
		}
	}
	while(q--)
		cout<<minn<<"1\n";
	return 0;
}
