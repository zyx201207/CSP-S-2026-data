#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int w[500005],k[505],a[505][500005],t[505][500005],l[100005],r[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
	}
	for(int i=1;i<=q;i++){
		cin>>l[i]>>r[i];
		int ans=0;
		ans=ans+w[l[i]]+w[r[i]];

	}
	return 0;
}
