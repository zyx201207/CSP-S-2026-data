#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define S second
#define F first
const ll N=1e6+5,mod=1e9+7,inf=1e18;
ll n,m,a[N],ans[N],vis[N];
stack<ll> s; 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		while(!s.empty()) s.pop();
		for(int j=1;j<=m;j++) vis[j]=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]>0){
				while(!s.empty()&&s.top()!=a[j]){
					ll k=s.top();
					vis[k]--;
					s.pop();
				}
			}
			else{
				s.push(a[j]);
				vis[a[j]]++;
			}
		}
		for(int j=1;j<=m;j++) if(vis[j]>0) ans[j]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}


