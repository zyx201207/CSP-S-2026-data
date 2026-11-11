#include<bits/stdc++.h>
using namespace std;
int a[2000006];
int n,d;
int b[2000006];
int zd[2000006];
void dfs1(int dv,int ju){
	if(zd[dv]==0||zd[dv]>ju){
		zd[dv]=ju;
	}
	for(int i=dv+1;i<=n;i++){
		if(a[i]-a[dv]<=d){
			dfs1(i,ju+1);
		}else{
			break;
		}
	}
	return ;
}
void dfs2(int dv,int ju){
	if(zd[dv]==ju)
	b[(dv+ju*n*2)%2000006]++;
	for(int i=dv+1;i<=n;i++){
		if(a[i]-a[dv]<=d){
			dfs2(i,ju+1);
		}else{
			break;
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=2000002;i++){
			b[i]=0;
			zd[i]=0;
		}
		dfs1(1,0);
		dfs2(1,0);
		int je=0;
		for(int i=1;i<=2000002;i++){
			je+=(b[i]==2);
		}
		cout<<je<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


*/