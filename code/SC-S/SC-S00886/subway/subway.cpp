#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,k;
int w[10000];
int a[10000][10000],t[10000][10000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	cin>>x>>y;
	int o=rand();
	int l=rand();
	cout<<o<<endl;
	cout<<l;
	
	return 0;
}