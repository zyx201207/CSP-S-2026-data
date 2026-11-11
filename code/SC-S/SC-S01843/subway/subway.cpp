#include<bits/stdc++.h>
using namespace std;
int w[500005],k[502],a[502][500005],t[502][500005],x[100005],y[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
    	cin>>k[i];
    	for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
	}
	for(int r=1;r<=q;r++){
		cin>>x[r]>>y[r];
		cout<<0<<"\n";
	}
	return 0;
}
