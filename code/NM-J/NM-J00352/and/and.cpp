#include<bits/stdc++.h>
using namespace std;
const long long N =2e5+10;
long long n,m;
long long a[N];
long long maxx=-1;
void dfs(int depth,int len,long long now){
	if(len>m)return;
	if(len==m){
		maxx=max(maxx,now); 
		return; 
	}
	if(depth==n+1)return;
	if(len==0){
		dfs(depth+1,len+1,a[depth]);
	}else{
		dfs(depth+1,len+1,now&a[depth]);
	}
	dfs(depth+1,len,now); 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<maxx<<endl;
	return 0;
}
