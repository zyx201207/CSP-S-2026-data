#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll arr[500001],c[500001];
bool f[500001];
ll maxn=-1;
void dfs2(ll step,ll sum){
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
		    if (c[j]==c[i]&&c[j]!=-1){
		    	c[i]+=c[j];
		    	c[j]=-1;
		    	if (f[i]&&f[j]){
		    		dfs2(step+1,sum);
				}
				else if (f[i]){
					f[j]=1;
		    		dfs2(step+1,sum+1);
		    		f[j]=0;
				}
				else if (f[j]){
					f[i]=1;
		    		dfs2(step+1,sum+1);
		    		f[i]=0;
				}
				else{
					f[i]=f[j]=1;
		    		dfs2(step+1,sum+2);
		    		f[i]=f[j]=0;
				}
			}
    	}
	}
	maxn=max(maxn,sum);
}
int dfs(ll step){
	if (step>m){return 0;}
	for (int i=1;i<=n;i++){
		arr[i]++;
		dfs(step+1);
		arr[i]--;
	}
	dfs2(0,0);
	return maxn;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (ll i=1;i<=n;i++){cin>>arr[i];}
	cout<<dfs(0);
	return 0;
}
