#include<bits/stdc++.h>
using namespace std;
long long a[100100];
long long maxx = 0;
long long n,m;
void dfs(long long x,long long y,long long z){
	if(x>=m){
		maxx = max(maxx,y);
		return ;
	}
	if(z>n)return ;
	if(y==0){
		dfs(x+1,a[z],z+1);
		dfs(x,y,z+1);
	}else{
		int q = y&a[z];
		dfs(x+1,q,z+1);
		dfs(x,y,z+1);
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n;
	cin >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	dfs(0,0,1);
	cout << maxx;
	return 0;
} 
