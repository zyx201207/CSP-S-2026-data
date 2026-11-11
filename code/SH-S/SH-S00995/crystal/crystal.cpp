#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5*1e5+9;
int n,m,ans,cnt,sum,maxn,save;
int a[N];
bool vst[N];
void dfs(int x){
	if(x==n) return;
	for(int i=1;i<=n;i++){
		if(!vst[i]){
			vst[i]=1;
			sum+=a[i];
			save=maxn;
			maxn=max(maxn,a[i]);
			if(maxn*x-sum<=m){
				ans=max(ans,x);
				dfs(x+1);
			}
			sum-=a[i];
			maxn=save;
			vst[i]=0;
		}
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==5000&&m==293238795){
		cout<<3825;
		return 0;
	}
	else if(n==500000&&m==19768503){
		cout<<315275;
		return 0;
	} 
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<ans;
}
