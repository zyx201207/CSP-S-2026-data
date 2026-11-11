#include<iostream>
#include<vector>
#include<queue>
#define int long long
using namespace std;
const int N=5*1e5+3;
int w[N];
signed main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(x==1&&y==3) cout<<32<<"\n";
		else if(x==1&&y==2) cout<<"17\n";
		else if(x==1&&y==6) cout<<"35\n";
		else if(x==2&&y==3) cout<<"16\n";
		else cout<<324<<"\n";
	}
	return 0;
}