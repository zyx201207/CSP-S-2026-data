#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],mx=-1;
void dfs(long long u,long long c,long long sum){
	if(c==m){
		mx=max(mx,sum);
		return ;
	}if(u>n){
		return;
	}dfs(u+1,c+1,sum&a[u]);
	dfs(u+1,c,sum);
	
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}dfs(1,0,pow(2,31)-1);
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
