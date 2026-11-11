#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],mx=0,b[10005];
void dfs(int f,int j){
	if(f==m){
		long long x=b[1];
		for(int i=2;i<=m;i++){
			x=x&b[i];
		}
		mx=max(mx,x);
	}
	for(int i=j+1;i<=n;i++){
		b[f]=a[i];
		dfs(f+1,i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<mx;
	return 0;
}
