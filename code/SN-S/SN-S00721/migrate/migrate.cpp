//准考证号:SN-S00721     姓名:强小轩
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ldb long double
#define eps 1e-7
const int maxn=2e6+10;
const int maxm=1e5+10;
const int mod1=1e9+7;
const int mod2=998244353;
using namespace std;
typedef pair<int,int> Pii;
ll c,t,n,maxd,ans,x[maxn],prevv[maxn],nextt[maxn],d[maxn],cnt[maxn],sum[maxn];
bool vis[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>maxd;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			d[i-1]=x[i]-x[i-1];
			prevv[i]=i-1;
			nextt[i]=i+1;
			cnt[i]=1;
//			cout<<nextt[2]<<'\n';
		}
		prevv[n+1]=n;
		nextt[0]=1;
		ll now_sum=0;
		for(int winl=1,winr=2;winr<=n;winr=nextt[winr]){
			now_sum+=x[winr]-x[prevv[winr]];
			while(now_sum>=maxd){
				now_sum-=d[winl];
				winl=nextt[winl];
			}
			if(now_sum<=maxd){
				if(winl!=1&&d[winl]+d[prevv[winl]]<=maxd)continue;
				if(winr!=n&&d[prevv[winr]]+d[winr]<=maxd)continue;
//				cout<<winl<<' '<<winr<<'\n';
				prevv[nextt[winr]]=winl;
				d[winl]=d[winr];
				for(int i=nextt[winl];i<=winr;i=nextt[i]){
					vis[i]=1;
					prevv[i]=winl,nextt[i]=nextt[winr];
					cnt[winl]++;
				}
				nextt[winl]=nextt[winr];
				now_sum=0;
			}
		}
		x[1]=0;
		for(int i=nextt[1];i<=n;i=nextt[i]){
			x[i]=x[prevv[i]]+d[prevv[i]];
		}
		for(int i=1;i<=n;i++){
			if(vis[i])x[i]=x[prevv[i]];
		}
		x[0]=-1e18L;
		d[0]=1e18L;
		x[n+1]=3e18L;
		d[n]=1e18L;
		for(int i=1;i<=n;i=nextt[i]){
			sum[i]=sum[prevv[i]]+cnt[i];
		}
		sum[n+1]=sum[n];
//		cout<<nextt[2]<<'\n';
//		for(int i=1;i<=n+1;i++){
//			cout<<x[i]<<' '<<d[i]<<' '<<cnt[i]<<' '<<sum[i]<<'\n';
//		}
		ans=0;
		for(int i=nextt[nextt[1]];nextt[i]<=n;i=nextt[i]){
//			cout<<i<<'\n';
			int r1=upper_bound(x+1,x+1+n,x[prevv[prevv[i]]]+maxd)-x;
			int r2=upper_bound(x+1,x+1+n,x[prevv[i]]+maxd)-x;
			ll sumr=sum[prevv[r2]]-sum[prevv[r1]];
			int l2=lower_bound(x+1,x+1+n,x[nextt[i]]-maxd)-x;
			int l1=lower_bound(x+1,x+1+n,x[i]-maxd)-x;
			ll suml=sum[prevv[l2]]-sum[prevv[l1]];
//			cout<<i<<' '<<l1<<' '<<l2<<' '<<r1<<' '<<r2<<' '<<suml<<' '<<sumr<<'\n';
			ans+=suml*sumr;
		}
		cout<<ans<<'\n';
	}
	return 0;
} 























