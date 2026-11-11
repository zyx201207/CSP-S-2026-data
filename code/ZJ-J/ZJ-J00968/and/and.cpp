#include<bits/stdc++.h>
using namespace std;
int a[2000010],b[10000010];
int n,m,ma=INT_MIN;
void dfs(int con,int i){
	if(con==m){
		int ji=b[1];
		for(int j=2;j<=m;j++){
			ji&=b[j];
		}ma=max(ma,ji);
		return;
	}
	for(int j=i;j<=n;j++){
		b[con+1]=a[j];
		dfs(con+1,j+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1);
	cout<<ma;
	return 0;
}