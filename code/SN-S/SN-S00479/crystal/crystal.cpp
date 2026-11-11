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
#define Max(x,y) (x)=max((x),(y))
#define status 1
 //0表示测样里，1表示提交，2表示侧大杨丽，一定要改成1
#define filename "crystal"//注意改文件名！！！！
const int maxn=5e5+202;
ll n,m;
ll a[maxn],b[maxn];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll sum=0,ans=0;
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ll j=i;
		for(int step=1<<20;step;step>>=1){
			if(j>step&&(i-j+step)*a[i]<=b[i-1]-b[j-step-1]+m){
				j-=step;
			}
		}
//		cout<<i<<" "<<j<<"sdf\n";
		Max(ans,i-j+1);
	}
	cout<<ans<<endl;
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
