#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int x[N];
int n,m;
int maxn=-1;
void dfs(int d,int t){
	if(d>m){
		int sum=x[1];
		for(int i=2;i<=m;i++){
			sum&=x[i];
		}
		maxn=max(maxn,sum);
		return;
	}
	for(int i=t+1;i<=n;i++){
		x[d]=a[i];
		dfs(d+1,i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn&=a[i];
		}
		cout<<maxn;
		return 0;
	} 
	dfs(1,0);
	cout<<maxn;
	return 0;
}