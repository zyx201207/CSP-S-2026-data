#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[500005];
int a[505][500005];
int t[505][500005];
bool v[505][500005];
int mi=2147483647;
void dfs(int y,int st,int ti,int su){
	if(st==y){
		if(mi>ti){
			mi=ti;
		}
		return;
	}
	for(int i=0;i<n;i++){
		
	}
}
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		if(x==y){
			cout<<0;
		}
	}
	return 0;
}

