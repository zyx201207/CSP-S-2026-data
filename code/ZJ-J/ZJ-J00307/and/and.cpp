#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+7;
int n,m,ans=-1;
int a[MAXN];
bool u[MAXN];
void dfs(int now,int sum){
	if(now==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(u[i]==0){
			if(now==0) sum=a[i];
			else sum=sum&a[i];
			u[i]=1;
			dfs(now++,sum);
			if(now!=0) u[i]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0);
	cout<<ans;
	return 0;
}
/*
4 2 3 15 12 12


5 3 31 3 1 15 7
*/
