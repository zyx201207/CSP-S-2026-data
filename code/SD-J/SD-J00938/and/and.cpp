#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int dfs(int x,int s,int c){
	cout<<x<<" "<<s<<" "<<c<<endl;
	if(x==m){
		return s;
	}
	if(c==n){
		return 0;
	}
	for(int i=c;i<=n;i++){
		return max(dfs(x+1,s&a[i],i),dfs(x,s,i));
	}
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(0,0,0);
	return 0;
}
