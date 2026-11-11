#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,a[500050],x,y;
long long w[500050],t[50050];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>a[i]>>t[i];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		int ans=w[x]+w[y];
		cout<<ans+t[x]+t[y];
	}
	return 0;
}

 
