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
#define filename "hub"//注意改文件名！！！！
const int maxn=4002;
int cid,T,n,k;
vector<int> e[maxn];
int dp[maxn][maxn][2];//考虑第i个点，目前最小填了的深度为j，填了1/2个联通快时最小填入的基地数 
int dep[maxn],mxdep[maxn];
#define Max(x,y) (x)=max((x),(y))
#define Min(x,y) (x)=min((x),(y))
void make_tree(int pos,int fa){
	mxdep[pos]=dep[pos]=dep[fa]+1;
	streps(i,e[pos])
	if(i!=fa){
		make_tree(i,pos);
		Max(mxdep[pos],mxdep[i]);
	}
	sort(all(e[pos]),[](int x,int y){
		return mxdep[x]>mxdep[y];
	});
}
void dfs(int pos,int fa,int maxc){
	for(int i=dep[pos];i<=mxdep[pos];i++) dp[pos][i][0]=dp[pos][i][1]=dp[pos][i][2]=0x3f3f3f3f;
	dp[pos][dep[pos]][0]=1;
	int nc=0;
	streps(i,e[pos])
	if(i!=fa){
		dfs(i,pos,maxc);
		int tp[maxn][2]={};
		memset(tp,0x3f,sizeof(tp));
		for(int k=dep[i];k<=mxdep[i];k++){
			for(int j=dep[pos];j<=mxdep[pos];j++)
			if(j+k-dep[pos]-dep[i]<=2*maxc){
				for(int o=1;o<=2;o++)
					for(int p=1;p<=2;p++){
						int c=o+p-(k==dep[i]&&j==dep[pos]);
						if(c<=2){
							Min(tp[min(j,k)][c-1],dp[pos][j][o-1]+dp[i][k][p-1]);
						}
					}
			}
		}
		if(nc){
			for(int j=dep[pos];j<=mxdep[pos];j++) if(j-dep[i]+mxdep[i]-dep[pos]+1<=maxc) for(int o=0;o<=1;o++) Min(tp[j][o],dp[pos][j][o]);
			for(int j=dep[i];j<=mxdep[i];j++)
			if(j-dep[i]+mxdep[pos]-dep[pos]+1<=maxc) for(int o=0;o<=1;o++) Min(tp[j][o],dp[i][j][o]); 
		}
		else{
		 if(mxdep[i]-dep[pos]<=maxc)	Min(tp[dep[pos]][0],dp[pos][dep[pos]][0]); 
			for(int j=dep[i];j<=mxdep[i];j++)
			if(j-dep[pos]<=maxc) for(int o=0;o<=1;o++) Min(tp[j][o],dp[i][j][o]); 
		}
		nc=1;
		memcpy(dp[pos],tp,sizeof(tp));
	}
//	cout<<pos<<", "<<maxc<<":\n";
//	for(int i=dep[pos];i<=mxdep[pos];i++) cout<<dp[pos][i][0]<<" "<<dp[pos][i][1]<<endl;
}
void solve(){
	cin>>cid>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) e[i].clear(),mxdep[i]=dep[i]=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].pb(v);
			e[v].pb(u);
		}
		make_tree(1,0);
		int ans=-1;
		for(int i=1<<20;i;i>>=1){
			dfs(1,0,ans+i);
			int mn=0x3f3f3f3f;
			for(int j=1;j<=mxdep[1];j++) Min(mn,min(dp[1][j][0],dp[1][j][1]));
			if(mn>k) ans+=i;
		}
		cout<<ans+1<<endl;
	}
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
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
