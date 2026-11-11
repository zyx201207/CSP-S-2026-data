#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int a=[m+1],s=[n+1][m/n];
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int x=1;x<=n;x++){
		for(int j=1;j<=m/n;j++){
			cin>>s[x][j];
		}
	}
	cout<<a<<s;
	return 0;
}
