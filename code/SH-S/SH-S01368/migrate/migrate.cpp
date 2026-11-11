#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N = 2e6+5;
int c, t, n, d;
ll cnb[N], cnf[N];
int main(){
	freopen("migrate","r",stdin);
	freopen("migrate","w",stdout);
	cin >> c >> t;
	while(t--){
		ll ans=0;
		cin >> n >> d;
		int p=1;
		for(int i=1; i<=n; i++){
			cin >> a[i];
		}
		for(int i=2; i<=n; i++){
			while(a[i]-a[p]>d) p++;
			cnb[p]=cnf[i]=i-p;
		}
		int cnt=1;
		for(int i=1; i<=n; i++){
			if(cnb[i]==1){
				cnt++;
				continue;
			}
			queue<pii>q;
			q.push({i,0});
			ll p=0;
			int vis[N]={}, vt[N]={};
			while(!q.empty()){
				int t=q.front.first, r=q.front.second;
				q.pop();
				if(r>vis[t]) continue;
				if(r==vis[t]) vt[t]+=;
				for(int it=1; it<=cnb[t]; it++){
					q.push({i+it,r+1})
				}
			}
			ans+=cnt*;
			cnt=1;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
