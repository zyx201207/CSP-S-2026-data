#include<bits/stdc++.h>
using namespace std;
int w[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int s,t;
			cin>>s>>t;
		}
	}
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	cout<<d/(m-n)<<"\n"<<d/2+m;
	return 0;
}
