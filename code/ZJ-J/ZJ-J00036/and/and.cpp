#include<bits/stdc++.h>
using namespace std;
int a[200005],n,k,mx=-1;
void dfs(int x,int m,int s){
	if(m==k){
		mx=max(mx,s);
		return ;
	}
	for(int i = x+1;i<=n+m-k+1;i++){
		dfs(i,m+1,s&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	int sss=1;
	for(int i = 1;i<=30;i++){
		sss*=2;
	}
	sss--;
	dfs(0,0,sss);
	cout<<mx;
	return 0;
}
