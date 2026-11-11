#include<bits/stdc++.h>
#define ll long long
#define inf 999999999999999
using namespace std;
const int N=505;
const int M=5e5+10;
int c,n,m,d,q;
ll w[M];
vector<ll>s[M];
vector<ll>t[M];
ll dis[N][N];
ll xxx;
ll a,b;
ll ans;
ll aaa,bbb;
ll min(ll a,ll b){
	return a<b?a:b;
}
void init(){
	for(int i=1;i<=503;i++){
		for(int j=1;j<=503;j++){
			if(i!=j)dis[i][j]=inf;
		}
	}
	for(int lin=1;lin<=m;lin++){
		for(int i=0;i<s[lin].size();i++){
			for(int j=i+1;j<s[lin].size();j++){
				dis[s[lin][i]][s[lin][j]]=min(dis[s[lin][i]][s[lin][j]],t[lin][i]+t[lin][j]);
				dis[s[lin][j]][s[lin][i]]=dis[s[lin][i]][s[lin][j]];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>xxx;
		while(xxx--){
			cin>>a>>b;
			s[a].push_back(i);
			t[a].push_back(b);
		}
	}
	init();
	while(q--){
		cin>>aaa>>bbb;
		ans=inf;
		for(int i=0;i<s[aaa].size();i++){
			for(int j=0;j<s[bbb].size();j++){
				ans=min(ans,dis[s[aaa][i]][s[bbb][j]]+t[aaa][i]+t[bbb][j]);
			}
		}
		cout<<ans+w[aaa]+w[bbb]<<'\n';
	}
	return 0;
}