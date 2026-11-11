#include<bits/stdc++.h>
using namespace std;
int n,m;
long long N=1;
long long a[200005],ans;
void dfs(int id,int cnt,long long k){
	if(id>n)return;
	if(cnt==m){
		ans=max(ans,k);
		return;
	}
	dfs(id+1,cnt+1,(k&a[id+1]));
	dfs(id+1,cnt,k);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=31;i++)N*=2;
	N--;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,0,N);
	cout<<ans;
	return 0;
}
