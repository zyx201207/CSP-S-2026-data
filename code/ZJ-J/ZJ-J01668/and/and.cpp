#include <bits/stdc++.h>
using namespace std;
const int N=1e5*2+5;
long long n,m,ans=0;
bool f[N];
long long a[N],y[N];
void check(){
	long long sum=a[y[1]];
	for(int i=2;i<=m;i++) sum=(sum&a[y[i]]);
	ans=max(ans,sum);
	return;
}
void dfs(int k){
	if(k>m){
		check();
		return;
	}
	else{
		for(int i=y[k-1];i<=n;i++){
			if(!f[i]){
				f[i]=1;
				y[k]=i;
				dfs(k+1);
				f[i]=0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}