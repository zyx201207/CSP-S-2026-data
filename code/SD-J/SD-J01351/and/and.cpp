#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans=0;
long long a[200010];
long long arr[200010];
void dfs(long long x,long long start){
	if(x==m+1)
	{
		long long res=arr[1];
		for(long long i=2;i<=m;i++){
			res=arr[i]&res;
		}
		ans=max(ans,res);
		return ;
	}
	for(long long i=start;i<=n;i++){
		arr[x]=a[i];
		dfs(x+1,i+1);
		arr[x]=0;
	}
}
int main(){	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
