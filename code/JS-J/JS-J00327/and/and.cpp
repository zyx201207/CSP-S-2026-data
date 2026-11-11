#include<bits/stdc++.h>
using namespace std;
long long ann=1,amn=1,c; 
int n,ans=-1e9,m;
int a[1000001];
void dfs(int pos,int w,int ah){
	if(pos==m)ans=max(ah,ans);
	else if(n-w+1<m-pos)return;
	else {
		dfs(pos+1,w+1,ah&a[w]);
		dfs(pos,w+1,ah);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,1,0);
	cout<<ans;
	return 0;
}
