#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int a[N],mo[2005][2005],n,m;
int dfs(int x,int k){
	if(k==m){
		return pow(2,31)-1;
	}
	if(x>n) return 0;
	if(mo[x][k]!=-1) return mo[x][k];
	int ans=-1;
	int y=dfs(x+1,k+1)&a[x];
	ans=max(dfs(x+1,k),dfs(x+1,k+1)&a[x]);
	return mo[x][k]=ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	memset(mo,-1,sizeof(mo));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(1,0);
	return 0;
} 
