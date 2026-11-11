#include <bits/stdc++.h>

using namespace std;
#define int long long
int m , n , b[200005] , mx;
void dfs(int q , int w ,int e){
	if(w==n){
		mx=max(mx,e);
		return;
	}
	if(q==m+1){
		return;
	}
	if(e==-1){
		dfs(q+1,w+1,b[q]);
		dfs(q+1,w,-1);
	}else{
		dfs(q+1,w+1,(e&b[q]));
		dfs(q+1,w,e);
	}
}
signed main(){
	freopen("and.in" , "r" ,stdin);
	freopen("and.out" , "w" ,stdout);
	cin >> m>>n;
	for(int i = 1;i <= m;i++){
		cin >> b[i];
	}
	dfs(0,0,-1);
	cout << mx;
	return 0;
} 
