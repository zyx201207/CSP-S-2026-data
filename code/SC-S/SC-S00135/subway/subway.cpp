#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int N=3e5+5;
ll n,m,d,q,ans2=INT_MAX,jjj;
ll a[N],c[500][N],use[N];
vector<ll> go[500];
void dfs(ll x,ll y,ll ans,ll z){
	if(x==y){
		ans2=min(ans2,ans);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(c[i][x]!=0){
			for(int j=0;j<go[i].size();j++){
				if(use[go[i][j]]==0){
					use[go[i][j]]=1;
					dfs(go[i][j],y,ans+c[i][x]+c[i][go[i][j]],i);
	
					use[go[i][j]]=0;
				}
			}
		}
	}
	return ;
}
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>jjj>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			cin>>x>>c[i][x];
			go[i].push_back(x);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans2=INT_MAX;
		dfs(x,y,a[x]+a[y],0);
		cout<<ans2<<endl;
	}
	return 0;
} 