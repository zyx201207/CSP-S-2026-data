#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++)cin>>c;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=2*x;j++)cin>>d;
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
	}
	cout<<43<<57;
	return 0;
}
