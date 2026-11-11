#include<bits/stdc++.h>
using namespace std;
const int N=2E6+5;
int a[N];
int c,t,n,d,zd,cnt,ls;
void dfs(int x,int y,int bs){
	if(bs>zd) return;
	if(x>y) return;
	if(x==y){
		if(bs==zd){
			ls++;
		}
		return;
	}
	for(int i=1;i<=d;i++){
		if(x+i<=y){
			dfs(x+i,y,bs++);
		}
	}
}
int cyz(){
	cin>>n>>d;
	cnt=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ls=0;
			zd=(a[j]-a[i])/d;
			dfs(i,j,0);
			if(ls==2) cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) cyz();
	return 0;
}
