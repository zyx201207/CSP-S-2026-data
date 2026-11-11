#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,x=0,y=0;
int b[200005];
void dfs(int u,int s){
	if(u>m){
		x=b[1];
		for(int i=2;i<=u-1;i++){
			x&=b[i];
		}
		if(x>y){
			y=x;
		}
		return;
	}
	for(int i=s+1;i<=n+u-m;i++){
		dfs(u+1,i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		x=a[1];
		for(int i=1;i<=n;i++){
			x&=a[i];
			cout<<x;
		}
		cout<<x;
		return 0;
	}
	dfs(1,0);
	cout<<y;
	return 0;
}