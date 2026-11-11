#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],maxn=-1;
bool f[200005];
//不会，直接暴搜QwQ 
void dfs(int x,int s){
	if(x>m){
		maxn=max(maxn,s);
		return ;
	} 
	for(int i=1;i<=n;i++){
		//没用过 
		if(!f[i]){
			f[i]=1;
			//进入下一层 
			if(x==1) dfs(x+1,a[i]);
			else{
				int s1=s&a[i];
				dfs(x+1,s1);
			}
			f[i]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0);
	cout<<maxn;
	return 0;
}
//问世间情为何物，只教生死相许，
//天南地北双飞客，老翅几回寒暑，
//知趣别，离别苦，就中更有痴儿女，
//君应有语，渺万里层云，孤影向谁去？ 
