#include<bits/stdc++.h>
using namespace std;
int m,n;
unsigned long long a[200005];
unsigned long long mx=0;

void dfs(int now,int x,unsigned long long b){
	if(x==m+1){
		mx=max(mx,b);
		return;
	}
	if(x==n+1 || x+n-now+1<m){
		return;
	}
	dfs(now+1,x,b);
	dfs(now+1,x+1,b==-1 ? a[now] : b&a[now]);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}	
		cout<<mx;
		return 0;
	}
	mx=0;
	dfs(1,0,-1);
	cout<<mx;
	return 0;
}