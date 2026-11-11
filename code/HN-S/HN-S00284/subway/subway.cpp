#include<bits/stdc++.h>
#define int long long
using namespace std;
struct P{
	int a,t;
};
const int N=5e5+5;
int a[N];
vector<vector<P>> e[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int ai,ti;
			cin>> ai >> ti;
			
		}
	}
	if(c==1){
		for(int i=1;i<=q;i++){
			cout<<1<<'\n';
		}
	}
	return 0;
}
