#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int w[600];
int k;
int a[600];
int x,y;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
 	cin>>c>>n>>m>>d>>p;
 	for(int i=1;i<=m;i++){
 		cin>>w[i];
	}
	for(int i=1;i<=2;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i];
		}
	}
	for(int i=1;i<=p;i++){
		cin>>x>>y;
	}
	return 0;
}

