#include<bits/stdc++.h>
using namespace std;
int  n,m,a[200005],b[200005],maxn;
void dfs(int step,int flag){
	if(step==m+1){
		int n=b[1];
		for(int i=2;i<=m;i++){
			n=n&b[i];
		}
		maxn=max(maxn,n);
		return;
	}
	for(int i=flag;i<=n;i++){
	    b[step]=a[i];
	    dfs(step+1,i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1);
	cout<<maxn;
	return 0;
}
