//cfl422 SN-S00479 xianshitieyizhongxue

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define y1 absyyyy121
#define fir first
#define sec second
#define pb push_back
#define mkp make_pair
#define sz(s) (int)(s.size())
#define all(v) v.begin(),v.end()
#define strep(i,s) for(int i=0;i<sz(s);i++)
#define streps(i,s) for(auto i:s)
#define fastread ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
typedef pair<ll,ll> pl;

#define status 1 //0表示测样里，1表示提交，2表示侧大杨丽，一定要改成1
#define filename "subway"//注意改文件名！！！！
const int maxn=502,maxm=5e5+202,sumk=5e5+202;
int cid,n,m,d,q;//注意n是铁路总数，m是站点总数，sumk是边数
#define int long long 
int a[maxm];
struct Subway{
	int a,t;//a是站点，t是站点换乘的时间 
};
vector<Subway> s[maxm];
int f[maxn][maxn];
void solve(){
	cin>>cid>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int aa,tt;
			cin>>aa>>tt;
			s[aa].pb(Subway{i,tt});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	#define Min(x,y) (x)=min((x),(y)) 
	for(int i=1;i<=m;i++){
		strep(j,s[i])
			for(int o=j+1;o<sz(s[i]);o++){
				Min(f[s[i][j].a][s[i][o].a],s[i][j].t+s[i][o].t);
			}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=f[j][i]=min(f[i][j],f[j][i]);
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	Min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=0x3f3f3f3f3f3f3f3f;
		streps(j,s[x])
		streps(o,s[y]){
			Min(ans,j.t+o.t+f[j.a][o.a]);
		}
		cout<<ans+a[x]+a[y]<<endl;
	}
}
signed main(){
	#if status == 1
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	#elif status == 2
	string t;
	cin>>t;
	freopen((filename+t+".in").c_str(),"r",stdin);
	freopen((filename".out"),"w",stdout);
	#endif
	#if status != 0
	fastread;
	#endif
	solve();
	return 0;
} 
