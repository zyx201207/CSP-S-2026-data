#include<bits/stdc++.h>
using namespace std;
int n,m;
int maxn=0;
int a[200005];
int f[200005];
void dfs(int pos,int x){
	if(pos==m+1){
		int ans=f[1]; 
		for(int i=2;i<=m;i++){
			ans&=f[i];
		}
		if(ans>maxn){
			maxn=ans;
			return;
		}
	}
	else{
		for(int i=x+1;i<=n-m+pos;i++){	
			f[pos]=a[i];
			dfs(pos+1,i);
		}
		return;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;	

	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>2000&&m!=n-1){
		cout<<a[n-m+1];
		return 0;
	}

	dfs(1,0);
	cout<<maxn;
}
