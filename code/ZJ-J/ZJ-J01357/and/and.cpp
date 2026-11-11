#include<iostream>
#include<stdio.h>
using namespace std;
int n,m,t[200005],mx;
void dfs(int x,int k,int c){
	if(k==m){
		if(x>mx) mx=x;
		return;
	}
	for(int i=c;i<n-m+k+1;i++){
		dfs(x&t[i],k+1,i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>t[i];
	mx=0;
	dfs(0x7fffffff,0,0);
	cout<<mx;
	return 0;
}