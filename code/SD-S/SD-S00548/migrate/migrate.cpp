#include<bits/stdc++.h>
#define l(x) ((x)&-(x))
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define A first
#define B second
#define CT continue
#define rt return
#define umap unordered_map
#define pq priority_queue
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int N=2e6+10;
const int LOG=21;
int n,T,C,l[N],r[N];
ll res,a[N],d,x,dp[N],tot[N];vi v[N];
queue<int> q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
//	cout<<fixed<<setprecision(2);
	cin>>C>>T;
while(T--){
	cin>>n>>d;res=0;
	for(int i=1;i<=n;i++)
		dp[i]=tot[i]=0,v[i].clear();
	for(int i=1;i<=n;i++){
		cin>>x;a[i]=x;
		while(q.size()&&a[q.front()]<x-d){
			if(q.front()<i-1)
				r[q.front()]=i-1,v[i-1].pb(q.front());
			else r[q.front()]=-1;q.pop();
		}
		if(q.size()) l[i]=q.front();
		else l[i]=-1;
		q.push(i);
	}
	while(q.size()) r[q.front()]=n,q.pop();
	for(int i=2;i<=n;i++){
		if(r[i]==-1||r[i]==i+1||
		r[i]==n||v[i].empty()) continue;
		if(r[i-1]<r[i]-1) dp[i]=
		v[i].size()+dp[v[i][0]];
	}
	for(int i=n;i>1;i--){
		if(r[i-1]==n||r[i]==-1) continue;
	//	if(r[i-1]<r[i]) tot[i]=tot[r[i]]+1;
	}
	for(int i=1;i<=n;i++){
		if(r[i]==-1||r[i]==i+1||r[i]==n||
		l[r[r[i]-1]]!=r[i]-1) continue;
		res+=(dp[i]+1)*(tot[r[r[i]-1]]+1);
	}
	cout<<res<<'\n';
}
	
	return 0;
}







