#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[200005];
int sum=0;
int ans[500005];
int maxx=0;
void dfs(int u,int v){
	if(v>m){
		maxx=max(maxx,sum);
	}
	for(int i=u;i<=n-m+1;i++){
		if(v==1){
			sum=a[i];
			dfs(i+1,v+1);
		}else{
			int x=sum;
			sum&=a[i];
			dfs(i+1,v+1);
			sum=x;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","W",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2000){
		dfs(1,1);
		cout<<maxx;
	}else{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	return 0;
}
/*
核桃打钱！
*/