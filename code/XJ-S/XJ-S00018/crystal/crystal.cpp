#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m,a[500010],v[25],ans;
void dfs(ll x,ll step){
	if(step==m){
		memset(v,0,sizeof(v));
		for(int i=1;i<=n;i++){
			v[a[i]]++;
		}
		sort(v+1,v+21,greater<int>());
		ans=max(ans,v[1]);
		return;
	}
	for(int i=1;i<=n;i++){
		a[i]++;
		dfs(i,step+1);
		a[i]--;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,0);
	cout<<ans;
	return 0;
} 
