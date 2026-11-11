#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long a[500005];
vector<pair<int,long long> >p[505];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x;long long y;
		cin>>x>>y;
		p[i].push_back({x,y});
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=a[x]+a[y];
		//
	}
	return 0;
} 
