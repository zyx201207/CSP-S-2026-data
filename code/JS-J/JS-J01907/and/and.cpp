#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200009],xz,ans;
void dfs(long long sz,long long sy,long long ai){
	if(sy==0){
		ans=max(ans,sz);
		return;
	}
	if(n-ai+1<sy)
		return;
	dfs(sz&a[ai],sy-1,ai+1);
	dfs(sz,sy,ai+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ans=-1;
	if(n<=2000){
		dfs(16*16*16*16*16-1,m,1);
		cout<<ans;
	}
	else{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	return 0;//Score||Treat!
}
