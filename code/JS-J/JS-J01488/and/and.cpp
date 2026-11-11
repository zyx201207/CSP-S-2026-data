#include<iostream>
#define ll long long
using namespace std;

ll a[100005],maxx;
	ll n,m;
bool vis[100005];

void dfs(ll u,ll dep,ll now){
	if(dep>m)return;
	if(dep==m){
		maxx=max(maxx,now);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(i,dep+1,now&a[i]);
			vis[i]=0;
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m!=2)dfs(0,0,~0);
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					maxx=max(maxx,a[i]&a[j]);
				}
			}
		}
	}
	cout<<maxx;
}