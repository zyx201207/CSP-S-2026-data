#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const int M=6e5+5;
const ll INF=1e18;
struct edge{
	int to;
	ll w;
};
struct node{
	int bh,w;
};
struct cord{
	int x;
	ll dis;
	bool operator <(const cord& rhs) const{
		return dis>rhs.dis;
	}
};
vector<edge> p[M];
vector<node> w[M];
vector<ll> a[M],t[M];
int T,n,m,d,q,len[M];
ll ans,wx[M],pwp[M],dis_n[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	//LL!
	cin>>T>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>wx[i];
	for(int i=1;i<=n;i++){
		cin>>len[i];
		a[i].resize(len[i]+5);t[i].resize(len[i]+5);
		for(int j=1;j<=len[i];j++){
			cin>>a[i][j]>>t[i][j];
			p[i+m].push_back(edge{a[i][j],t[i][j]});
			p[a[i][j]].push_back(edge{i+m,t[i][j]});
			w[a[i][j]].push_back(node{i,t[i][j]});
		}
	}
	memset(dis_n,0x3f,sizeof(dis_n));
	for(int i=1;i<=n;i++) dis_n[i][i]=0;
	for(int i=1;i<=n;i++){
		for(auto j:p[i+m])
			pwp[j.to]=j.w;
		for(int j=1;j<=n;j++)
			for(auto k:p[j+m])
				if(pwp[k.to])
					dis_n[i][j]=min(dis_n[i][j],pwp[k.to]+k.w);
		for(auto j:p[i+m])
			pwp[j.to]=0;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis_n[i][j]=min(dis_n[i][j],dis_n[i][k]+dis_n[k][j]);
	while(q--){
		int st,ed;
		cin>>st>>ed;
		ans=INF;
		for(auto u:w[st])
			for(auto v:w[ed])
				ans=min(ans,wx[st]+wx[ed]+u.w+v.w+dis_n[u.bh][v.bh]);
		cout<<ans<<"\n";
	}
	return 0;
}
/*
16:35
O(ndmlogdm+qd^2)
expect:68pts

17:35
O(nm+n^3+qd^2)
expect:100pts
fc subway7.ans my.out 找不到差异
这题绝对是青，我第一次场青
弥补了去年没有场切图论 T2 的遗憾
Maybe today J 400pts,S 255 pts?
have a good time
不过我这么菜也是去不了 WC 了，祝你们 zhzx 的初三巨佬们加油，我先 out 一步了
*/