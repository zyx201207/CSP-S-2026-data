#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500010],a[510][500010],id,t[510][500010],l,r;
struct node{
	int to,val;
};
vector<node> g[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>id;
		for(int j=1;j<=id;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		cin>>l>>r;
		int ans=0;
		for(int i=l;i<=r;i++){
			ans+=t[1][i];
		}
		cout<<ans+w[l]+w[r]<<endl;
	}
	return 0;
}

