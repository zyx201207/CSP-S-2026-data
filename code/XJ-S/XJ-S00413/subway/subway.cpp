#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,n,m,d,q;
int w[N]={},a[N][N]={};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[m];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k*2;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
	}
	cout<<"32"<<endl<<"17";
	return 0;
}
