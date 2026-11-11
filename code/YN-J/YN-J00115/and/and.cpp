#include <bits/stdc++.h>
using namespace std;
int n,m;
long long ans,a[200005];
int dfs(long long u,long long an,long long c){
	if (u==n+1){
		if (c==m){
			return an;
		}else{
			return 0;
		}
	}
	if (c>m){
		return 0;
	}
	long long s1;
	if (an==0){
		s1=dfs(u+1,a[u],c+1);
	}else{
		s1=dfs(u+1,(an&a[u]),c+1);
	}
	long long s2=dfs(u+1,an,c);
	return max(s1,s2);
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(1,0,0)<<endl;
	return 0;
}
