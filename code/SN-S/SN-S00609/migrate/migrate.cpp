#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+10;
ll c,t,a[maxn],n,d;
struct edge{
	ll belong,direct;
};
vector<edge>G[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			G[i].push_back({n,a[i]});
		}
	}
}
