#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
bool t[200005];
void dfs(long long k,long long cc){
	if(cc>=m) {
		long long  p=(1<<30)-1;
		for(int i=1;i<=n;i++) if(t[i]){
			p&=a[i];
		}
		ans=max(p,ans);
		return;
	}
	if(k>n) return;
	t[k]=1;
	dfs(k+1,cc+1);
	t[k]=0;
	dfs(k+1,cc);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=2000){
		dfs(1,0);
		cout<<ans;
	}
	return 0;
}