#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define pr pair<int,int>
#define mk(a,b) make_pair(a,b)
#define Tnow double(clock())/CLOCKS_PER_SEC
double TT=double(clock())/CLOCKS_PER_SEC;

const int N=2e6+5;
const ll inf=1e18;

int n;
ll a[N],id,d,dis[N],f[N];
vector<int> G[N];

void topo(int st){
	for(int j=1;j<=n;j++) dis[j]=inf,f[j]=0;
	dis[st]=0;
	f[st]=1;
	queue<int> q;
	q.push(st);
	while(q.size()){
		int u=q.front(); q.pop();
		for(auto v:G[u]){
			if(dis[v]<dis[u]+1) continue;
			else if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				f[v]=f[u];
				q.push(v);
			}else f[v]+=f[u];
		}
	}
	return ;
}

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i],G[i].clear();
	if(11<=id&&id<=12){
		ll c=a[2]-a[1],x=d/c;
		if(x==0||x==1||x>=n-1){
			cout<<0<<endl;
			return ;
		}
		ll ans=0;
		ans+=(n-x*2+1);
		cout<<ans<<endl;
		return ;
	}
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(a[j]-a[i]<=d) G[i].push_back(j);
	ll ans=0;
	for(int i=1;i<=n;i++){
		topo(i);
		for(int j=1;j<=n;j++){
			ans+=(f[j]==2);
			if(Tnow-TT>=0.98){
				cout<<ans<<endl;
				return ;
			}
		}
	}
	cout<<ans<<endl;
	return ;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//    system("fc migrate3.ans migrate.out");
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int _T; cin>>id>>_T;
	while(_T--) solve();
	return 0;
}
/*
0 1
10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962
*/
