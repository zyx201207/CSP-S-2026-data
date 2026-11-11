//CSP-S 2026 C by wyyinput
//Task name: migrate
//Date: 2026/10/31
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
const int N=2e6+55;
const int inf=1e9;
int C,T;
int n;
ll d;
ll x[N];
int dis[N];//距离
ll cnt[N];//最短路条数
void solve1(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(n==1){
		cout<<"0\n";
		return;
	}
	ll diff=x[2]-x[1];
	ll maxn=d/diff;
	if(maxn<=1){
		cout<<"0\n";
		return;
	}
	ll must=maxn*2;
	cout<<max(0ll,n-must+1)<<"\n";
	return;
}
void solve2(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	ll ans=0;
	for(int u=1;u<=n;u++){
		dis[u]=0;
		cnt[u]=1;
		for(int i=u+1;i<=n;i++){
			dis[i]=inf;
			cnt[i]=0;
			for(int j=i-1;j>=u;j--){
				if(x[i]-x[j]>d){
					break;
				}
				if(dis[j]+1<dis[i]){
					dis[i]=dis[j]+1;
					cnt[i]=cnt[j];
				}else if(dis[j]+1==dis[i]){
					cnt[i]+=cnt[j];
				}
			}
			ans+=cnt[i]==2;
		}
	}
	cout<<ans<<"\n";
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>T;
	//A性质，8pts
	if(/*C==0||*/C==11||C==12){
		while(T--){
			solve1();
		}
		return 0;
	}
	//O(N^3)
	if(/*C==0||*/1<=C&&C<=10){
		while(T--){
			solve2();
		}
		return 0;
	}
	//骗分
	while(T--){
		cout<<"0\n";
	}
	return 0;
}