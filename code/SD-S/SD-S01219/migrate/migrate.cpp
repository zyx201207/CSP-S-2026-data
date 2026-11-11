#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define mkp make_pair
#define psb push_back
const int N=2e6+1000;
const int inf=1e17;
int c,T,n,a[N],D;
int tol[N];
int dp[N],cnt[N],scnt[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
//	system("fc migrate.ans migrate.out");return 0;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>D;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c==11||c==12){
			int d=a[2]-a[1];
			int tms=D/d;
			if(tms<=1) cout<<"0\n";
			else cout<<max(0ll,n-tms*2+1)<<"\n";
			continue;
		}if(c==13||c==14){
			int rt=0;
			for(int i=1;i<=n;i++){
				if(a[i]-a[1]<=D||a[n]-a[i]<=D){
					rt=i;break;
				}
			}
			int ans=0;
			for(int i=1;i<=rt;i++){
				int tor=0;
				if(a[n]-a[i]<=D) tor=n;
				else if(a[i+1]-a[i]>D) tor=i;
				else{
					int l=i+1,r=n;
					while(l<r){
						int mid=((l+r+1)>>1);
						if(a[mid]-a[i]<=D) l=mid;
						else r=mid-1;
					}tor=l;
				}
				if(tor!=rt) ans=ans+n-tor;
			}cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i]-a[1]<=D) tol[i]=1;
			else if(a[i]-a[i-1]>D) tol[i]=i;
			else{
				int l=1,r=i-1;
				while(l<r){
					int mid=((l+r)>>1);
					if(a[i]-a[mid]<=D) r=mid;
					else l=mid+1;
				}tol[i]=l;
			}
		}
		
		if(c<=10){
			int ans=0;
			for(int st=1;st<=n;st++){
				dp[st]=0;cnt[st]=1;scnt[0]=1;
				int j=st;
				for(int i=st+1;i<=n;i++){
					if(tol[i]==i) break;
					while(j<tol[i]) scnt[dp[j]]-=cnt[j],j++;
					dp[i]=dp[tol[i]]+1;
					cnt[i]=min(3ll,scnt[dp[i]-1]);
					if(cnt[i]==2) ans++;
					scnt[dp[i]]+=cnt[i];
				}for(int i=0;i<=n;i++) dp[i]=cnt[i]=scnt[i]=0;
			}cout<<ans<<"\n";
		}

	}
	return 0;
}
/*

*/
