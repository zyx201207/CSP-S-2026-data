#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N=2e6+10;
const int M=11;
const int INF=1e18;
//int a[N],l[N],r[N];
//int dp[N][M];
//int c[M];
//bool ch[N][N];
//namespace working{
//	void solve(){
//		int n,d;cin>>n>>d;
//		for(int i=1;i<=n;i++){
//			cin>>a[i];ch[i]=false;
//		}for(int i=1;i<=n;i++){
//			l[i]=lower_bound(a+1,a+1+n,a[i]-d)-a;
//			r[i]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
//		}int tot=0,cnt=1;
//		for(int i=1;i<=n;i++) dp[i][0]=1;
//	//	for(int i=1;i<=n;i++) cerr<<l[i]<<" "; cerr<<"\n";
//	//	for(int i=1;i<=n;i++) cerr<<r[i]<<" "; cerr<<"\n";
//		while(tot==n){
//			for(int i=1;i<=n;i++){
//				for(int j=l[i];j<=r[i];j++){
//					dp[i][cnt]+=dp[j][cnt-1];
//				}
//			}
//		}
//		return ;
//	}
//}
int a[N],s[N],ans[N];
bool ck[N];
int n,d;
void Init(){
	for(int i=1;i<=n;i++){
		ans[i]=0;ck[i]=false;s[i]=INF;
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}int res=0;
	queue<pair<int,int>> qu;//id step
	
	for(int i=1;i<=n;i++){
		qu.push({i,0});
		while(!qu.empty()){
			auto q=qu.front();qu.pop();
			int u=q.fi,sp=q.se;
			if(ck[u]&&sp==s[u]){
				ans[u]++;
				continue;
			}if(ck[u]) continue;
			ck[u]=true;s[u]=sp;
			for(int j=1;j<=n;j++){
				if(a[j]!=a[u]&&abs(a[j]-a[u])<=d){
//					cerr<<"prev:"<<u<<" now:"<<j<<"\n";
					qu.push({j,sp+1});
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(ans[j]==1){
				res++;
//				cerr<<"AAA";
			}
//			cerr<<ans[j]<<" ";
		}
//		cerr<<"\n";
		Init();
	}cout<<res/2<<"\n";
//	cerr<<res/2<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;cin>>c>>T;
	//我已红温，明明感觉比去年的题简单的
	//为啥这次这么坎坷
	while(T--)solve();
	return 0;
}