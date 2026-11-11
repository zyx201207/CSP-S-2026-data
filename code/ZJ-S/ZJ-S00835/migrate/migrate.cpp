#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
const int N=2e6+10,M=5e2+10,MOD=1e9+7;
const ll inf=1e18;
ll c,n,d,ans,x[N];
//1~6
ll dis1[310][310],cnt1[310];
void bfs(ll st){
	for(int i=1;i<=n;i++) cnt1[i]=0;
	queue<pa> q;
	q.push({st,0});
	while(!q.empty()){
		pa node=q.front();
		q.pop();
		ll x=node.first,w=node.second;
		cnt1[x]++;
		for(int i=1;i<=n;i++){
			if(dis1[st][i]==w+1&&dis1[x][i]==1) q.push({i,w+1});
		}
	}
	for(int i=1;i<=n;i++){
		if(cnt1[i]==2) ans++;
	}
}
void main1(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(abs(x[i]-x[j])<=d) dis1[i][j]=1;
			else dis1[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis1[i][j]=min(dis1[i][j],dis1[i][k]+dis1[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++) bfs(i);
	cout<<ans/2<<"\n";
}
//11,12
void main2(){
	ll D=x[2]-x[1];
	ll t=d/D;
	if(t<2) cout<<"0\n";
	else cout<<max(0ll,n-(2*t-1))<<"\n";
}
void solve(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++) cin>>x[i];
	if(c<=6) main1();
	else if(c==11||c==12) main2();
	else main1();
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	IOS;
	int _=1;
	cin>>c>>_;
	while(_--) solve();
	return 0;
}
/*

*/
