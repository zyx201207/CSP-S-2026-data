#include<bits/stdc++.h>
using namespace std;
struct trees{
	int h[5111]={};
};
int a[511111],w[511111],k[511111];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
		}
	}
	cout<<a[8][9]<<'\n';
	return 0;
}
