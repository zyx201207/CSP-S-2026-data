#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N];
int n,m,ans=-1;
void dfs(int x,int tmp,int st){
	if(x==m){
		ans=max(ans,tmp);
		return ;
	}
	for(int i=st;i<=n;i++)
		dfs(x+1,(tmp&a[i]),i+1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=10000){
		for(int i=1;i<=n;i++)
			dfs(1,a[i],i+1);
		cout<<ans;
	}
	else{
		sort(a+1,a+n+1);
		cout<<a[n];	
	}
	return 0;
}
