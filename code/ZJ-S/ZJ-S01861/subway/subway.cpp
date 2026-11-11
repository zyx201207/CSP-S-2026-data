#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll c,n,m,d,q;
ll w[N],a[510][N],t[510][N];
struct node{
	ll u,w;
};
ll dist[510][510]
void solveA(){
	vector<node> v;
	for(int i=1;i<=n;i++){
		if(k<2)continue;
		v[a[i][1]].push_back({a[i][2],t[i][1]+t[i][2]});
		v[a[i][2]].push_back({a[i][1],t[i][1]+t[i][2]});
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		a[i][0]=k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	if(c>=7&&c<=11){
		solveA();
	}
	
	
	return 0;
}