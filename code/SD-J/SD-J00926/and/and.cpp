#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long maxx=INT_MIN;
long long dfs(long long strat,long long now,long long ji){
	if(now==m){
		return ji;
	}
	for(long long i=strat;i<=n-(m-now)+1;i++)
		maxx=max(maxx,dfs(i+1,now+1,ji&a[i]));
	return  maxx;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(1,0,INT_MAX);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
