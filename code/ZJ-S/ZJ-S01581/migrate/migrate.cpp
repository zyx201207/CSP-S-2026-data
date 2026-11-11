#include<bits/stdc++.h>
#pragma GCC optimize(2,3,"Ofast","inline")
#define int long long
using namespace std;
int c,t,n,d,x[2005005],mi,ms,s;
void dfs(int p,int mb,int st){
	if(p==mb){
		if(mi>st){mi=st;ms=0;}
		if(mi==st)ms++;
		return;
	}
	int h=p+1;
	while(h<=mb&&x[h]-x[p]<=d){dfs(h,mb,st+1);h++;}
}
void guo_mj(){
	cin>>n>>d;s=0;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			mi=11451411;ms=0;
			dfs(i,j,0);
			if(ms==2)s++;
		}
	}
	cout<<s<<endl;
}
signed main(){
  freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		guo_mj();
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