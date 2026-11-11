#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Q=1e5+5;
ll c,n,m,d,q;
ll k;
ll w[505];
ll a[Q],t[Q];
struct node{
	int x,y;
}r[Q];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	while(n--){
		cin>>k;
		for(int i=1;i<=k*2;i++){
			cin>>a[i]>>t[i];
			
		}
		for(int i=1;i<=q;i++){
			cin>>r[i].x>>r[i].y;
		}
		cout<<n+m+d+p<<'\n';
	}
	return 0;
}
