#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int a[N],p[N],n;
int dp[N],b[N],f[N],q[N],fr,bk;
void add(int x,int k){for(;x<=n;x+=x&-x)b[x]+=k;}
int sum(int x,int ret=0){for(;x;x-=x&-x)ret+=b[x];return ret;}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;cin>>C>>T;
	while(T--){
		int d,ans=0;cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			p[i]=dp[i]=b[i]=f[i]=0;
		}if(n==1){cout<<0<<'\n';continue;}
		if(C==11||C==12){
			int x=a[2]-a[1];
			if(2*x>d)ans=0;
			else{
				int c=d/x;
				ans=max(0ll,n-2*c+1);
			}cout<<ans<<'\n';
			continue;
		}int r=n;
		for(int i=n;i;i--){
			while(a[r]-a[i]>d)r--;
			p[i]=r;
		}if(C==13||C==14){
			int k=0;
			for(int i=1;i<=n;i++){
				if(a[i]-a[1]<=r&&a[n]-a[i]<=r){
					k=i;break;
				}
			}for(int i=1;i<k;i++){
				if(p[i]-k>1)break;
				if(p[i]>2)ans+=p[p[i]-1]-p[p[i]-2];
			}cout<<ans<<'\n';
			continue;
		}for(int r=1;r<=n;r++){
			fr=1;bk=0;
			dp[r]=1;add(r,1);
			for(int i=r-1;i;i--){
				f[i]=f[p[i]]+1;
				if(f[i]>f[i+1])q[++bk]=i+1;
				while(fr<=bk&&q[fr]>p[i])fr++;
				if(fr>bk)break;
				dp[i]=sum(p[i])-sum(q[fr]-1);
				add(i,dp[i]);
			}for(int i=1;i<=n;i++){
				if(dp[i]==2)ans++;
				dp[i]=b[i]=0;
			}
		}cout<<ans<<'\n';
	}
	return 0;
}
