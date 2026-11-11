#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,k,ans=1e18;
int w[500005];
struct node{
	int w;
	vector<int> p;
	map<int,int> q;
}a[500005];
struct Node{
	int id,co,ce;
};
vector<int> p[500005];
map<int,int> ui[500005];
int dd[500005][50];
void dfs(int qx,int zx,int x,int color,int sum){
	if(x==zx){
		ans=min(ans,sum);
		return ;
	}
	int koi=p[x].size();
	for(int t=0;t<koi;t++){
		int ok=p[x][t];
		int uio=a[ok].p.size();
		for(int i=0;i<uio;i++){
			if(dd[ok][a[ok].p[i]]==1) continue;
			if(color==a[ok].p[i]){
				dd[ok][a[ok].p[i]]=1;
				dfs(qx,zx,ok,color,sum);
				dd[ok][a[ok].p[i]]=0;
			}else{
				dd[ok][a[ok].p[i]]=1;
				dfs(qx,zx,ok,a[ok].p[i],sum+a[x].q[color]+a[ok].q[a[ok].p[i]]);
				dd[ok][a[ok].p[i]]=0;
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int s;
	cin>>c>>m>>n>>d>>k;
		for(int t=1;t<=n;t++) cin>>a[t].w;
		for(int t=1;t<=m;t++){
			int o,o2,so;
			cin>>s;
			for(int i=1;i<=s;i++){
				cin>>o>>o2;
				a[o].q[t]=o2;
				a[o].p.push_back(t);
				if(i>1&&ui[so][o]==0){
					p[so].push_back(o);
					ui[so][o]=1;
				}
				so=o;
			}
		}
		int qx,zx;
		for(int t=1;t<=k;t++){
			ans=1e18;
			cin>>qx>>zx;
			int kop=a[t].p.size();
			for(int t=0;t<kop;t++)
			dfs(qx,zx,qx,t,a[qx].w+a[qx].q[a[qx].p[t]]);
			cout<<ans<<"\n";
		}
	return 0;
}
