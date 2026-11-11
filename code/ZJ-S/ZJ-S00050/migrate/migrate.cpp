#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
ll a[N];
ll dis[N];
ll ans,tmp;
bool vis[N],flag;
vector<pair<int,int>>to[N];
void spfa(int s){
	queue<pair<int,int>>q;
//	for(int i=1;i<=n;i++){
//		dis[i]=0;
//	}
}
void solve(){
	ans=0;
	int n;
	ll d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	flag=true;
	for(int i=1;i<n;i++){
		a[i]=a[i+1]-a[i];
		if(i==1){
			tmp=a[i];
		}
		else{
			if(a[i]!=tmp){
				flag=false;
			}
		}
	}
	if(flag)
	{
		ans+=(d/tmp)*n*n;
		ans+=2;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			//to[i].push_back();
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
