#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define inf 1000000000000000000
#define vec vector<ll>
#define pii pair<ll,ll>
#define all(x) x.begin(),x.end()
using namespace std;

ll max(ll a,ll b){return (a<b?b:a);}
ll min(ll a,ll b){return (a>b?b:a);}
ll lowbit(ll x){return x&(-x);}
ll ksm(ll a,ll d,ll mo=mod){
	a%=mo;
	ll ans=1;
	for(;d;d>>=1){
		if(d&1)ans=ans*a%mo;
		a=a*a%mo;
	}
	return ans;
}

ll c,n,m,d,q,w[500005],dis[505][505],t1,t2,subs[505],ans;
vec a[505],t[505];
vec sta[500005],sti[500005];

void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>subs[i];
		for(int j=1;j<=subs[i];j++){
			cin>>t1>>t2;
			a[i].push_back(t1);
			t[i].push_back(t2);
			sta[t1].push_back(i);
			sti[t1].push_back(t2);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=inf;
		} 
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<sta[i].size();j++){
			for(int k=0;k<j;k++){
				dis[sta[i][j]][sta[i][k]]=min(dis[sta[i][j]][sta[i][k]],sti[i][j]+sti[i][k]);
				dis[sta[i][k]][sta[i][j]]=min(dis[sta[i][k]][sta[i][j]],sti[i][j]+sti[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		ans=inf;
		for(int j=0;j<sta[t1].size();j++){
			for(int k=0;k<sta[t2].size();k++){
				ans=min(ans,dis[sta[t1][j]][sta[t2][k]]+sti[t1][j]+sti[t2][k]);
			}
		}
		cout<<ans+w[t1]+w[t2]<<'\n'; 
	}
}

int main(){
//  system("fc subway7.ans subway.out");return 0;
//	freopen("subway7.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

//	ll t;
//	for(cin>>t;t;t--)
	solve();

	return 0;
}

/*
出这个题的人可能苦于公交问题（？）

简单而言，每个点有三部分，地铁口、站厅、站台。
线路是连接站台的。一个地铁站可能有多个站台，不超过d个。 
对于u地铁站，从地铁口到站厅需要时间w_u，站厅到线路x站台也要时间。

地铁口是假的。答案+w_s+w_t 
这个是不是直接建图就完了。
点数是m(d+1)的，边数是2md+\sum k的。
好的，图可以建，但是我们咋跑最短路。
你发现线路是不耗时的。
我们把线路kk成一个点，然后在可以换乘的地方连一下边。
然后floyd。 
然后询问，暴力枚举xy到底是哪个站，复杂度。 
O(md^2+n^3+qd^2)
做完了？ 
什么玩意没有计算器。

对面小朋友问什么是解压/oh 
*/

