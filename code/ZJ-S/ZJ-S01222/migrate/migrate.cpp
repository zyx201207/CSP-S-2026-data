#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll x[N];
ll bfs(int be,int d,int n){
	queue<pair<int,int> >q;
	q.push({be,0});
	vector<ll>step(n+1,2e6+1);
	vector<ll>a(n+1);
	while(!q.empty()){
		int u=q.front().first,w=q.front().second;
		q.pop();
		for(int i=u+1;i<=n;i++){
			if(x[i]-x[u]>d) continue;
			if(step[i]>w+1){
				step[i]=w+1;
				a[i]=1;
				q.push({i,w+1});
			}else if(step[i]==w+1){
				a[i]++;
				q.push({i,w+1});
			}
		}
	}
	ll sum=0;
	for(int i=be+1;i<=n;i++){
		if(a[i]==2) sum++;
	}
	return sum;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		ll ans=0;
		for(int i=1;i<=n-3;i++){
			ans+=bfs(i,d,n);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
