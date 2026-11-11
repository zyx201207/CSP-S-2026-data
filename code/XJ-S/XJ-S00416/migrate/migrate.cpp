#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e2+5;
int c,t,x[N],n,d,minn[N],maxn[N];
void dfs(int now,int cnt){
	if(now>x[n]) return;
	int flag=0;
	for(int i=1;i<=n;i++) if(now==x[i]) flag=i;
	if(flag!=0) return;
	for(int i=1;i<=n;i++){
		
	}
	if(cnt<=minn[flag]) maxn[flag]++;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++) dfs(i,0);
	}
	return 0;
} 
