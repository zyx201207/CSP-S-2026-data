#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m;
long long a[N];
long long maxx=INT_MIN;
long long b[N];
bool f[N];
void dfs(long long x,long long k){
	if(k==m+1){
		long long t=b[1];
		for(int i=2;i<=m;i++){
			t=t&b[i];
		}
		maxx=max(maxx,t);
		return ;
	}
	for(int i=x;i<=n;i++){
		if(!f[i]){
			b[x]=a[i];
			f[i]=true;
			dfs(x+1,k+1);
			b[x]=0;
			f[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1);
	cout<<maxx;
	return 0;
}
