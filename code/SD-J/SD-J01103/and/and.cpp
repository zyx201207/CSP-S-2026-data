#include<bits/stdc++.h>
using namespace std;
long long a[1000101];
long long n,m;
long long dfs(long long i,long long s,long long v){
	if(v==m){
		return s;
	}if(i==n+1&&v!=m){
		return -999;
	}
	if(s==0){
		return max(dfs(i+1,a[i],v+1),dfs(i+1,0,0));
	}else{
		return max(dfs(i+1,s&a[i],v+1),dfs(i+1,s,v));
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(1,0,0);
	return 0;
}

