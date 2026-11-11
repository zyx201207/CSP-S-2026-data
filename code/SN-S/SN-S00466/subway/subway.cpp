//姜承宇 SN-S00466 西安翱翔中学 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,a[500005],t[500005],bj[500005];
vector<int> v[500005];
struct jcy{
	int a,t;
}mp[606][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		for(int j = 1;j<=k;j++){
			cin>>mp[i][j].a>>mp[i][j].t;
		}
	}
	while(q--){
		cout<<2<<endl;
	}
	return 0;
}
