#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+5;
struct node{//tree
	int last,tm;
};
int c,n,m,d,q;
int w[M],a[N][M],k[N],t[N][M];
vector<node>mp[M];
void solve(){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=m;j++){
			
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j==1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		solve();
	}
}
