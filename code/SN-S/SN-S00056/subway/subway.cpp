#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,ans,n,m,d,q,w[500010],a[500][500010],t[500][500010],k,x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	return 0;
}
