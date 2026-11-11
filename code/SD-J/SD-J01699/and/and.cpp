#include<bits/stdc++.h>
using namespace std;
int a[100005];
int n,m;
int maxn;
void dfs(int x){
	if(x>=m){
		int s=a[1]; 
		for(int i=2;i<=m;i++){
			s=s&a[i];
		}
		maxn=max(s,maxn);
		return;
	}
	for(int i=1;i<=n;i++){
		a[x]=a[i];
		dfs(x+1);
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int s=0;
	for(int i=1;i<=n;i++){
		int x=a[i];
		x++;
		while(1){
			if(x%2==0)
			x/=2;
			else break;
		} 
		if(x==1) s++;
	}
	if(s==n){
		cout<<a[n-m+1];
		return 0;
	}
	dfs(1);
	cout<<maxn;
	return 0;
} 
/*
4 2
3 15 12 12
*/
