#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
typedef long long ll;
ll n,d,x[N],ans,dis[N];
void dfs(int u,int step){
	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);	
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			dis[i]=LLONG_MAX;
		}
		dis[1]=0;
		dfs(1,0);
		cout<<ans;
	}
	return 0;
} 
