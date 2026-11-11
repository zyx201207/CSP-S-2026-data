#include <bits/stdc++.h>
using namespace std;



int n,m,sum,i=1;
int maxn;
int l[10000005];
int dfs(int a){
	if(a==i+n){
		return l[i+n];
	} 
	else {
		return dfs(a+1) & l[a];
	}
}


int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> l[i];
	}
	for(int i=1;i<=m-n;i++){
		int x=dfs(i);
		maxn=max(x,maxn);
	}
	
	cout << maxn;
	return 0;
}
