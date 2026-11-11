#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
int r=0;
int n,k;
void dfs(int p,int c,int x){
	if((n-p)<(k-c)){
		return;
	}
	if(c==k){
		r=max(r,x);
		return;
	}
	for(int i=p+1;i<n;i++){
		dfs(i,c+1,x&a[i]);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		dfs(i,1,a[i]);
	}
	cout<<r<<endl;
	return 0;
}