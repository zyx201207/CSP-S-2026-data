#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int N=2e6+10;
int c,n,m,d,q,w[N],a[1000][20],t[1000][20];
signed main(){ IOS;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	int flag=1;
	for(int i=1;i<=n;i++){
		int nn; cin>>nn;
		if(nn>2) flag=0;
		for(int j=1;j<=nn;j++){
			cin>>a[i][j]>>t[i][j];
		}
		if(n==2&&a[i][1]>a[i][2]){
			swap(a[i][1],a[i][2]);
			swap(t[i][1],t[i][2]);
		} 
	}
	while(q--){
		int x,y; cin>>x>>y;
		if(x>y) swap(x,y);
		if(flag==1){
			int ans=w[x]+w[y];
			while(x!=y){
				ans+=t[x][1]+t[x][2];
				x=a[x][2];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}