#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m,a[N],maxn=-0x3f3f3f3f3f3f3f3f;
void dfs(int i,bool f,int sum,int x){
	if(x==m){
		maxn=max(sum,maxn);
		return ;
	}
	if(i>n)return ;	
	if(f)dfs(i+1,0,a[i],x+1);
	else dfs(i+1,f,(sum&a[i]),x+1);
	dfs(i+1,f,sum,x);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	dfs(1,1,0,0);
	cout<<maxn;
	return 0;
} 