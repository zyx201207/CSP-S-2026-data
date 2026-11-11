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

#define status 1//0表示测样里，1表示提交，2表示侧大杨丽，一定要改成1
#define filename "migrate"//注意改文件名！！！！
const int maxn=2e6+202;
ll cid,T,n,d;
ll x[maxn];
const int maxnn=5002;
int dp[maxnn];
ll dp2[maxnn];
#define inf (0x3f3f3f3f)
#define llinf (0x3f3f3f3f3f3f3f3f)
int cl[maxnn];//到每个节点最远能起飞的位置 
int cr[maxnn];//每个dp值对应的下标最大值 
void solve(){
	cin>>cid>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			cl[i]=i;
			for(int step=1<<20;step;step>>=1)
				if(cl[i]>step&&x[i]-x[cl[i]-step]<=d)
					cl[i]-=step;
		}
//		cerr<<1<<endl;
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j<=i) dp[j]=0;
				else dp[j]=inf;
			}
			for(int j=1;j<=n;j++) dp2[j]=0;
			for(int j=1;j<=n;j++) cr[j]=0;
			dp2[i]=1;
			cr[0]=i;
			for(int j=i+1;j<=n;j++){
				if(cl[j]==j){
					break;
				}
				else{
					int zcl=max(i,cl[j]);
					dp[j]=dp[zcl]+1;
	//				cerr<<dp[zcl]<"\n";
					dp2[j]=dp2[cr[dp[zcl]]]-dp2[zcl-1];
					cr[dp[j]]=j;
					if(dp2[j]==2) ans++;
//					cout<<i<<" "<<j<<" "<<dp[j]<<" "<<dp2[j]<<endl;
//					if(dp2[j]>2) break;
					dp2[j]+=dp2[j-1];
				}
			}
		}
		cout<<ans<<endl;
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
